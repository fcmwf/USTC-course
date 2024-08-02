package main

import (
	"math"
	"math/big"
	"bytes"
	"fmt"
	"crypto/sha256"
)

var (
	maxNonce  = math.MaxInt64
)

const targetBits = 8

// ProofOfWork represents a proof-of-work
type ProofOfWork struct {
	block  *Block
	target *big.Int
}

// NewProofOfWork builds and returns a ProofOfWork
func NewProofOfWork(b *Block) *ProofOfWork {
	target := big.NewInt(1)
	target.Lsh(target, uint(256-targetBits))

	pow := &ProofOfWork{b, target}

	return pow
}

// TODO
// Run performs a proof-of-work
// implement
func (pow *ProofOfWork) prepareData(nonce int) []byte {
	data := bytes.Join(
		[][]byte{
			IntToHex(pow.block.Header.Version),   //版本号
			pow.block.Header.PrevBlockHash[:],    //前一个区块的哈希值
			pow.block.Header.MerkleRoot[:],       //默克尔树根,当前区块数据对应哈希值
			IntToHex(pow.block.Header.Timestamp), //时间戳
			IntToHex(targetBits),                 //难度值
			IntToHex(int64(nonce)),               //随机数
		},
		[]byte{},
	)

	return data
}


func (pow *ProofOfWork) Run() (int64, []byte) {
	var hashInt big.Int
	var hash [32]byte
	var nonce  = 0 // 将 nonce 类型改为 int64

	fmt.Printf("Mining a new block")
	for nonce < maxNonce {
		data := pow.prepareData(nonce)

		hash = sha256.Sum256(data)
		hashInt.SetBytes(hash[:])

		if hashInt.Cmp(pow.target) == -1 {
			fmt.Printf("\r%x", hash)
			break
		} else {
			nonce++
		}
	}
	fmt.Print("\n\n")
	return int64(nonce) , hash[:]
}


// Validate validates block's PoW
// implement
func (pow *ProofOfWork) Validate() bool {
	var hashInt big.Int

	data := pow.prepareData(int(pow.block.Header.Nonce))
	hash := sha256.Sum256(data)
	hashInt.SetBytes(hash[:])

	isValid := hashInt.Cmp(pow.target) == -1

	return isValid
}
