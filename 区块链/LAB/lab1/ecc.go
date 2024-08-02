package main

import (
	"fmt"
	"math/big"

	"github.com/ethereum/go-ethereum/crypto"
	"github.com/ethereum/go-ethereum/crypto/secp256k1"
)

var (
	s256    *secp256k1.BitCurve = secp256k1.S256()
	P, _                        = new(big.Int).SetString("0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F", 0)
	N, _                        = new(big.Int).SetString("0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141", 0)
	B, _                        = new(big.Int).SetString("0x0000000000000000000000000000000000000000000000000000000000000007", 0)
	Gx, _                       = new(big.Int).SetString("0x79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798", 0)
	Gy, _                       = new(big.Int).SetString("0x483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8", 0)
	BitSize                     = 256
	G                           = &Point{Gx, Gy}
)

type Point struct {
	X *big.Int
	Y *big.Int
}

type Signature struct {
	s *big.Int
	r *big.Int
}

type ECC interface {
	Sign(msg []byte, secKey *big.Int) (*Signature, error)
	VerifySignature(msg []byte, signature *Signature, pubkey *Point) bool
}

type MyECC struct {
}

func NewPrivateKey() (*big.Int, error) {
	k, err := newRand()
	if err != nil {
		return nil, err
	}
	if err := checkBigIntSize(k); err != nil {
		return nil, fmt.Errorf("k error: %s", err)
	}

	return k, nil
}

func GeneratePublicKey(secKey *big.Int) *Point {
	return Multi(G, secKey)
}

func (ecc *MyECC) Sign(msg []byte, secKey *big.Int) (*Signature, error) {	
	k, err := newRand()
	if err != nil {
		return nil, err
	}
	r := Multi(G, k).X
	r = r.Mod(r,N)
	s := new(big.Int).SetBytes(crypto.Keccak256(msg))  
	secKey_mul_r := new(big.Int).Mul(secKey,r)
	secKey_mul_r  = secKey_mul_r.Mod(secKey_mul_r,N)
	s = s.Add(s,secKey_mul_r)
	s = s.Mod(s,N)
	kModN := Inv(k,N)
	s = s.Mul(s,kModN)
	s = s.Mod(s,N)
	var sign = &Signature{
		s : s,
		r : r,
	} 
	return sign,nil
}

// >>> point = S256Point(px, py)
// >>> s_inv = pow(s, N-2, N)  ❶
// >>> u = z * s_inv % N  ❷
// >>> v = r * s_inv % N  ❸
// >>> print((u*G + v*point).x.num == r)
func (ecc *MyECC) VerifySignature(msg []byte, signature *Signature, pubkey *Point) bool {
	hash_msg := new(big.Int).SetBytes(crypto.Keccak256(msg)) 
	reciprocal_s := Inv(signature.s,N)
	u := new(big.Int).Mul(reciprocal_s,hash_msg)
	u  = u.Mod(u,N)
	v := new(big.Int).Mul(reciprocal_s,signature.r)
	v  = v.Mod(v,N)
	uG := Multi(G,u)
	vP := Multi(pubkey,v)
	//res := new(big.Int).Add(uG.X,vP.X) 这里需要用椭圆曲线上的加法 故若用改代码结果错误！
	res := Add(uG,vP).X
	if res.Cmp(signature.r) == 0 {
		return true
	} else{ 
		return false
	}
}

func main() {
	seckey, err := NewPrivateKey()  //生成私匙
	if err != nil {
		fmt.Println("error!")
	}
	pubkey := GeneratePublicKey(seckey)  //生成公匙

	ecc := MyECC{}
	msg := []byte("test1")
	msg2 := []byte("test2")

	sign, err := ecc.Sign(msg, seckey)
	if err != nil {
		fmt.Printf("err %v\n", err)
		return
	}

	fmt.Printf("verify %v\n", ecc.VerifySignature(msg, sign, pubkey))
	fmt.Printf("verify %v\n", ecc.VerifySignature(msg2, sign, pubkey))

}
