package main

import (
	"crypto/sha256"
	"bytes"
	"math"
	"fmt"
)

// MerkleTree represent a Merkle tree
type MerkleTree struct {
	RootNode *MerkleNode
	Leaf     [][]byte
}

// MerkleNode represent a Merkle tree node
type MerkleNode struct {
	Left  *MerkleNode
	Right *MerkleNode
	Data  []byte
}

// NewMerkleTree creates a new Merkle tree from a sequence of data
func NewMerkleTree(data [][]byte) *MerkleTree {
	var nodes []MerkleNode

	if len(data)%2 != 0 {
		data = append(data, data[len(data)-1])
	}

	for _, datum := range data {
		node := NewMerkleNode(nil, nil, datum)
		nodes = append(nodes, *node)
	}

	height := int(math.Ceil(math.Log2(float64(len(data)))))

	for i := 0; i < height ; i++ {
		var newLevel []MerkleNode
		for j := 0; j < len(nodes); j += 2 {
			node := NewMerkleNode(&nodes[j], &nodes[j+1], nil)
			newLevel = append(newLevel, *node)
		}
		if len(newLevel)%2 != 0 {
			newLevel = append(newLevel, newLevel[len(newLevel)-1])
		}
		nodes = newLevel
	}

	return &MerkleTree{RootNode: &nodes[0], Leaf: data}
}

// NewMerkleNode creates a new Merkle tree node
func NewMerkleNode(left, right *MerkleNode, data []byte) *MerkleNode {
	node := new(MerkleNode)

	if left == nil && right == nil {
		hash := sha256.Sum256(data)
		node.Data = hash[:]
	} else {
		prevHashes := append(left.Data, right.Data...)
		hash := sha256.Sum256(prevHashes)
		node.Data = hash[:]
	}
	node.Left = left
	node.Right = right

	return node
}

func (t *MerkleTree) SPVproof(index int) ([][]byte, error) {
	leafCount := len(t.Leaf)
	if index >= leafCount {
		return nil, fmt.Errorf("no such leaf")
	}

	h := 0
	cnt := leafCount
	for cnt > 1 {
		cnt = cnt/2 + cnt%2
		h++
	}
	var path [][]byte
	node := t.RootNode
	for i := h; i > 0; i-- {
		signal := 1 << (i - 1)

		if index&signal == 0 {
			path = append(path, node.Right.Data)
			node = node.Left
		} else {
			path = append(path, node.Left.Data)
			node = node.Right
		}
	}
	return path, nil
}


func (t *MerkleTree) VerifyProof(index int, path [][]byte) (bool, error) {
	if index >= len(t.Leaf) {
		return false, fmt.Errorf("no Such Leaf")
	}
	data := sha256.Sum256(t.Leaf[index])
	signal := 1

	for i := len(path) - 1; i >= 0; i-- {

		if index&signal != 0 {
			tmp := append(path[i], data[:]...)
			data = sha256.Sum256(tmp)
		} else {
			tmp := append(data[:], path[i]...)
			data = sha256.Sum256(tmp)
		}
		signal = signal << 1
	}

	return bytes.Equal(data[:], t.RootNode.Data), nil
}
