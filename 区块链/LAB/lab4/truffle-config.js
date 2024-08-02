module.exports = {
  networks: {
    development: {
      host: "127.0.0.1",  // 本地host
      port: 8545,         // 本地端口（默认情况下为Ganache）
      network_id: "*",    // 匹配任何network id
    },
  },
  compilers: {
    solc: {
      version: "0.8.0",  // 指定Solidity编译器版本
    },
  },
};