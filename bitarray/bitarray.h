/****************************************************************************
	bitarray
AUTHOR: omer ido                                                   
CREATE DATE: 10/04/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __BITARRAY_H__
#define __BITARRAY_H__

#include <iostream> 
#include <vector>

namespace ilrd
{
static const size_t BITS_IN_WORD = 8 * sizeof(size_t);

template <std::size_t SIZE>
class BitArray
{
private:
	struct Proxy;

public:
	explicit BitArray();
	// using generated  CCtor, Dtor, op=
	
	void SetBit(std::size_t idx_, bool val_);
	bool GetBit(std::size_t idx_) const;
	void FlipBit(std::size_t idx_);
	void FlipAllBits();
	std::size_t CountTrueBits() const;

	bool operator==(const BitArray& other_) const;
	bool operator!=(const BitArray& other_) const;

	Proxy operator[](std::size_t idx_);
	bool operator[](std::size_t idx_) const;

	BitArray& operator|=(const BitArray& other_);
	BitArray& operator^=(const BitArray& other_);
	BitArray& operator&=(const BitArray& other_);

	BitArray& operator<<=(std::size_t num_bits);
	BitArray& operator>>=(std::size_t num_bits);

	void PrintBitArray(const BitArray& this_) const;
private:
	static const size_t NUM_CHUNKS = SIZE / (BITS_IN_WORD) + (SIZE % (BITS_IN_WORD));
	std::vector<size_t> m_bit_arr;
};

template<std::size_t SIZE>
struct BitArray<SIZE>::Proxy
{
	explicit Proxy(BitArray& bit_arr, std::size_t idx);

	Proxy& operator=(const Proxy& other_);
	Proxy& operator=(bool b_);
	operator bool();

	BitArray& v_ref;
	size_t m_idx;
};

template<std::size_t SIZE>
BitArray<SIZE>::BitArray(): m_bit_arr(NUM_CHUNKS)
{
	std::cout << " in Ctor! " << "	NUM_CHUNKS: " << NUM_CHUNKS << "\n";

	std::cout << "debug: sizeof(m_bit_arr): " << sizeof(m_bit_arr) << std::endl;
}


template<std::size_t SIZE>
void BitArray<SIZE>::SetBit(std::size_t idx_, bool val_)
{
	m_bit_arr[idx_] = val_;
}
//bool GetBit(std::size_t idx_) const;
//void FlipBit(std::size_t idx_);
//void FlipAllBits();
//std::size_t CountTrueBits() const;
//
//bool operator==(const BitArray& other_) const;
//bool operator!=(const BitArray& other_) const;
//
//Proxy operator[](std::size_t idx_);
//bool operator[](std::size_t idx_) const;
//
//BitArray& operator|=(const BitArray& other_);
//BitArray& operator^=(const BitArray& other_);
//BitArray& operator&=(const BitArray& other_);
//
//BitArray& operator<<=(std::size_t num_bits);
//BitArray& operator>>=(std::size_t num_bits);
}

#endif /* ifndef __BITARRAY_H__*/
