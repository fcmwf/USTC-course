// SPDX-License-Identifier: UNLICENSED
pragma solidity >=0.4.22;

contract BallotSystem {

    struct Voter {
        bool hasVoted;    
        uint weight;    
        uint8 selectedProposal;  
        address delegateAddress; 
    }

    struct Proposal {
        string title;    
        string description; 
        uint voteCount; 
        bool isActive; 
    }

    address public administrator;

    Proposal[] public proposalsList;

    uint public currentProposalCount;

    uint public constant MAX_UINT8 = (2**8) - 1;

    mapping(address => Voter) public voterRegistry;

    constructor(uint initialWeight) {
        administrator = msg.sender;
        voterRegistry[administrator].weight = initialWeight;
        
        for (uint i = 0; i <= MAX_UINT8; i++) {
            proposalsList.push(Proposal("", "", 0, false));
        }
    }

    function addProposal(string memory proposalTitle, string memory proposalDescription) public {
        require(currentProposalCount < MAX_UINT8, "Maximum proposal limit reached");

        currentProposalCount++;
        proposalsList[currentProposalCount].title = proposalTitle;
        proposalsList[currentProposalCount].description = proposalDescription;
        proposalsList[currentProposalCount].isActive = true;
    }

    modifier onlyAdministrator {
        require(msg.sender == administrator, "Action restricted to administrator");
        _;
    }

    modifier hasNotVoted(address voter) {
        require(!voterRegistry[voter].hasVoted, "Voter has already voted");
        _;
    }

    function authorizeVoter(address voter, uint weight) public onlyAdministrator hasNotVoted(voter) {
        require(weight >= 0 && weight <= 100, "Invalid voting weight");
        require(voterRegistry[voter].weight == 0, "Voter already authorized");
        voterRegistry[voter].weight = weight;
    }

    function delegateVote(address to) public hasNotVoted(msg.sender) {
        require(to != msg.sender, "Cannot delegate to self");
        
        while (voterRegistry[to].delegateAddress != address(0) && voterRegistry[to].delegateAddress != msg.sender) {
            to = voterRegistry[to].delegateAddress;
        }
        
        require(voterRegistry[to].delegateAddress != msg.sender, "Circular delegation not allowed");
        
        voterRegistry[msg.sender].delegateAddress = to;
        
        if (voterRegistry[to].hasVoted) {
            proposalsList[voterRegistry[to].selectedProposal].voteCount += voterRegistry[msg.sender].weight;
            voterRegistry[msg.sender].selectedProposal = voterRegistry[to].selectedProposal;
        } else {
            voterRegistry[to].weight += voterRegistry[msg.sender].weight;
        }
        
        voterRegistry[msg.sender].hasVoted = true;
    }

    function castVote(uint8 proposalID) public hasNotVoted(msg.sender) {
        require(proposalID >= 0 && proposalID <= MAX_UINT8, "Proposal ID out of range");
        require(proposalsList[proposalID].isActive, "Proposal is not active");
        
        proposalsList[proposalID].voteCount += voterRegistry[msg.sender].weight;
        voterRegistry[msg.sender].selectedProposal = proposalID;
        voterRegistry[msg.sender].hasVoted = true;
    }

    function winningProposal() public view returns (uint winningProposal_) {
        uint winningVoteCount = 0;
        for (uint p = 0; p < proposalsList.length; p++) {
            if (proposalsList[p].voteCount > winningVoteCount) {
                winningVoteCount = proposalsList[p].voteCount;
                winningProposal_ = p;
            }
        }
    }
}
