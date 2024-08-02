const BallotSystem = artifacts.require("BallotSystem");

module.exports = function(deployer) {
  // 部署 BallotSystem 合约
  deployer.deploy(BallotSystem,1);
};