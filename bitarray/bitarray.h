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
<<<<<<< HEAD
#include <algorithm>
=======
>>>>>>> e2c48ad8ccd6dea1560bb8ba23c5a911d98773a9

namespace ilrd
{
static const size_t BITS_IN_WORD = 8 * sizeof(size_t);

template <std::size_t SIZE>
<<<<<<< HEAD
class BitArray;

template <size_t SIZE>
std::ostream& operator<<(std::ostream& os, BitArray<SIZE>& ba);

template <std::size_t SIZE>
=======
>>>>>>> e2c48ad8ccd6dea1560bb8ba23c5a911d98773a9
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

<<<<<<< HEAD

=======
>>>>>>> e2c48ad8ccd6dea1560bb8ba23c5a911d98773a9
	BitArray& operator|=(const BitArray& other_);
	BitArray& operator^=(const BitArray& other_);
	BitArray& operator&=(const BitArray& other_);

	BitArray& operator<<=(std::size_t num_bits);
	BitArray& operator>>=(std::size_t num_bits);

	void PrintBitArray(const BitArray& this_) const;
private:
	static const size_t NUM_CHUNKS = SIZE / (BITS_IN_WORD) + (SIZE % (BITS_IN_WORD));
	std::vector<size_t> m_bit_arr;
<<<<<<< HEAD

	friend std::ostream& operator<< <SIZE>(std::ostream& os, BitArray<SIZE>& ba);
};

/* ******************* struct Proxy ********************************/
=======
};

>>>>>>> e2c48ad8ccd6dea1560bb8ba23c5a911d98773a9
template<std::size_t SIZE>
struct BitArray<SIZE>::Proxy
{
	explicit Proxy(BitArray& bit_arr, std::size_t idx);

	Proxy& operator=(const Proxy& other_);
	Proxy& operator=(bool b_);
	operator bool();

<<<<<<< HEAD
	BitArray& m_v_ref;
	size_t m_idx;
};


// ctor
=======
	BitArray& v_ref;
	size_t m_idx;
};

>>>>>>> e2c48ad8ccd6dea1560bb8ba23c5a911d98773a9
template<std::size_t SIZE>
BitArray<SIZE>::BitArray(): m_bit_arr(NUM_CHUNKS)
{
	std::cout << " in Ctor! " << "	NUM_CHUNKS: " << NUM_CHUNKS << "\n";
<<<<<<< HEAD
}

template<std::size_t SIZE>
std::ostream& operator<<(std::ostream& os, BitArray<SIZE>& ba)
{
	for(int i = 0; i < ba.NUM_CHUNKS; ++i)
	{
		for(int j = BITS_IN_WORD - 1; j >= 0; --j)
		{
			printf("%lu", ba.m_bit_arr[i] >> j & (size_t)1);

			if(j % 8 == 0)
			{
				printf(" ");
			}
//			std::cout << (ba.m_bit_arr >> j == 1 ? 1 : 0) << "\n";
		}
		printf("\n");
	}

	return os;
}

template<std::size_t SIZE>
void BitArray<SIZE>::SetBit(std::size_t idx_, bool val_)
{
	(m_bit_arr[idx_ / BITS_IN_WORD] &=
			~((size_t)1 << (idx_  % BITS_IN_WORD))) |=
			((size_t)val_ << (idx_ % BITS_IN_WORD));
}

template<std::size_t SIZE>
bool BitArray<SIZE>::GetBit(std::size_t idx_) const
{
	return(m_bit_arr[idx_ / BITS_IN_WORD] >> (idx_ % BITS_IN_WORD) & (size_t)1);
}

template<std::size_t SIZE>
void BitArray<SIZE>::FlipBit(std::size_t idx_)
{
	m_bit_arr[idx_ / BITS_IN_WORD] ^= ((size_t)1 << (idx_ % BITS_IN_WORD));
}
template<std::size_t SIZE>
void BitArray<SIZE>::FlipAllBits()
{
	size_t mask = ~(size_t)0;
//	size_t mask = 0xffffffffffffffff;
	mask <<= (SIZE % BITS_IN_WORD);
//	size_t mask = 0;
//	mask = ((size_t)1 << (BITS_IN_WORD - (SIZE % BITS_IN_WORD))) - 1;
	printf("			mask:  %lu\n", mask);
	printf("%lu\n", ~mask);

	int i = 0;
	for(; i < NUM_CHUNKS; ++i)
	{
		m_bit_arr[i] = ~m_bit_arr[i];
	}
	m_bit_arr[i - 1] &= ~mask;
}

template<std::size_t SIZE>
std::size_t BitArray<SIZE>::CountTrueBits() const
{
	size_t count = 0;
	size_t tmp;
	for(int i = 0; i < NUM_CHUNKS; ++i)
	{
		tmp = m_bit_arr[i];
		for(; tmp; ++count)
		{
			tmp &= (tmp - 1);
		}
	}
	return count;
}
template<std::size_t SIZE>
bool BitArray<SIZE>::operator==(const BitArray& other_) const
{
	return(m_bit_arr == other_.m_bit_arr);
}

template<std::size_t SIZE>
bool BitArray<SIZE>::operator!=(const BitArray& other_) const
{
	return(m_bit_arr != other_.m_bit_arr);
=======

	std::cout << "debug: sizeof(m_bit_arr): " << sizeof(m_bit_arr) << std::endl;
>>>>>>> e2c48ad8ccd6dea1560bb8ba23c5a911d98773a9
}


template<std::size_t SIZE>
<<<<<<< HEAD
bool BitArray<SIZE>	::operator[](std::size_t idx_) const
{
	return(this->GetBit(idx_));
}

template<std::size_t SIZE>
BitArray<SIZE>& BitArray<SIZE>::operator|=(const BitArray& other_)
{
	std::transform(m_bit_arr.begin(), m_bit_arr.end(),
			other_.m_bit_arr.begin(),
			m_bit_arr.begin(),
			std::bit_or<size_t>());

	return(*this);
}

template<std::size_t SIZE>
BitArray<SIZE>& BitArray<SIZE>::operator^=(const BitArray& other_)
{
	std::transform(m_bit_arr.begin(), m_bit_arr.end(),
			other_.m_bit_arr.begin(),
			m_bit_arr.begin(),
			std::bit_xor<size_t>());

	return(*this);
}

template<std::size_t SIZE>
BitArray<SIZE>& BitArray<SIZE>::operator&=(const BitArray& other_)
{
	std::transform(m_bit_arr.begin(), m_bit_arr.end(),
				   other_.m_bit_arr.begin(),
				   m_bit_arr.begin(),
				   std::bit_and<size_t>());

	return(*this);
}
//
//BitArray& operator<<=(std::size_t num_bits);
//BitArray& operator>>=(std::size_t num_bits);


/* ******************* struct Proxy ********************************/
template<std::size_t SIZE>
BitArray<SIZE>::Proxy::Proxy(BitArray& bit_arr, std::size_t idx):
								m_v_ref(bit_arr), m_idx(idx)
{}
template<std::size_t SIZE>
BitArray<SIZE>::Proxy& BitArray<SIZE>::Proxy::operator=(const Proxy& other_)
{
	return(*this = bool(other_));
}
template<std::size_t SIZE>
BitArray<SIZE>::Proxy& BitArray<SIZE>::Proxy::operator=(bool b_)
{
	m_v_ref.SetBit(m_idx, b_);
//	this->m_v_ref[m_idx] = b;
	return(*this);
}

template<std::size_t SIZE>
BitArray<SIZE>::Proxy::operator bool()
{
	return(m_v_ref.GetBit(m_idx));
}

}
=======
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

>>>>>>> e2c48ad8ccd6dea1560bb8ba23c5a911d98773a9
#endif /* ifndef __BITARRAY_H__*/
