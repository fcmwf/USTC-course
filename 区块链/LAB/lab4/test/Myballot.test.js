const Myballot = artifacts.require("Myballot");
const { expect } = require('chai');
const { BN, expectRevert } = require('@openzeppelin/test-helpers');

contract("Myballot", (accounts) => {
    let instance;
    const chairperson = accounts[0];
    const voter1 = accounts[1];
    const voter2 = accounts[2];

    beforeEach(async () => {
        instance = await Myballot.new(new BN(100), { from: chairperson });
    });

    it("should initialize the chairperson with the correct weight", async () => {
        const chairpersonVoter = await instance.voters(chairperson);
        expect(chairpersonVoter.weight).to.be.bignumber.equal(new BN(100));
    });

    it("should allow the chairperson to authorize a voter", async () => {
        await instance.authorizedVote(voter1, new BN(50), { from: chairperson });
        const voter1Details = await instance.voters(voter1);
        expect(voter1Details.weight).to.be.bignumber.equal(new BN(50));
    });

    it("should not allow non-chairperson to authorize a voter", async () => {
        await expectRevert(
            instance.authorizedVote(voter1, new BN(50), { from: voter2 }),
            "Only the chairman can operate"
        );
    });

    it("should allow a voter to apply a proposal", async () => {
        await instance.applyProposal("Proposal 1", "Proposal Content 1", { from: chairperson });
        const proposal = await instance.proposals(new BN(1));
        expect(proposal.name).to.equal("Proposal 1");
        expect(proposal.content).to.equal("Proposal Content 1");
        expect(proposal.enable).to.be.true;
    });

    it("should allow a voter to vote on a proposal", async () => {
        await instance.applyProposal("Proposal 1", "Proposal Content 1", { from: chairperson });
        await instance.authorizedVote(voter1, new BN(50), { from: chairperson });
        await instance.vote(new BN(1), { from: voter1 });
        const proposal = await instance.proposals(new BN(1));
        expect(proposal.voteCount).to.be.bignumber.equal(new BN(50));
    });

    it("should not allow double voting", async () => {
        await instance.applyProposal("Proposal 1", "Proposal Content 1", { from: chairperson });
        await instance.authorizedVote(voter1, new BN(50), { from: chairperson });
        await instance.vote(new BN(1), { from: voter1 });
        await expectRevert(
            instance.vote(new BN(1), { from: voter1 }),
            "Voting weight range exceeded"
        );
    });

    it("should allow delegation of voting rights", async () => {
        await instance.applyProposal("Proposal 1", "Proposal Content 1", { from: chairperson });
        await instance.authorizedVote(voter1, new BN(50), { from: chairperson });
        await instance.authorizedVote(voter2, new BN(30), { from: chairperson });
        await instance.delegateVoting(voter2, { from: voter1 });
        await instance.vote(new BN(1), { from: voter2 });
        const proposal = await instance.proposals(new BN(1));
        expect(proposal.voteCount).to.be.bignumber.equal(new BN(80));
    });
});