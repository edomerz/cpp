#include <cstdio>

#include "bitarray.h"

using namespace ilrd;

int main(void)
{


	printf("\n[FILE:%s][func:%s][LINE:%d]%s:\n", __FILE__, __func__, __LINE__, "Create1"); /* DEBUG!!! */
	BitArray<1> ba1;
	std::cout << "\nsizeof(ba1): " << sizeof(ba1)<< std::endl;
	
	printf("\n[FILE:%s][func:%s][LINE:%d]%s:\n", __FILE__, __func__, __LINE__, "Create2"); /* DEBUG!!! */
	BitArray<65> ba2;
//	std::cout << ba2;
//	ba2.FlipAllBits();
//	std::cout << ba2;

	BitArray<65> ba3;

	std::cout << "\nsizeof(ba2): " << sizeof(ba2)<< std::endl;

	std::cout << "\n";

	// Count True Bits
//	std::cout << "ba1.CountTrueBits(): " << ba1.CountTrueBits() << std::endl;
//	std::cout << "ba2.CountTrueBits(): " << ba2.CountTrueBits() << std::endl;

	// op==
//	std::cout << (ba3 == ba2) << std::endl;

//	std::cout << "\n";

	// Set Bit
	std::cout << ba1;
	ba1.SetBit(0,1);
	std::cout << ba1;
	std::cout << "ba1.CountTrueBits(): " << ba1.CountTrueBits() << std::endl;
	ba1.FlipAllBits();
	std::cout << ba1;
	ba1.FlipAllBits();
	std::cout << ba1;

	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";

//	ba2.SetBit(0,1);
//	ba2.SetBit(1,1);
	std::cout << "ba2.CountTrueBits(): " << ba2.CountTrueBits() << std::endl;

	std::cout << "(ba3 == ba2): " << (ba3 == ba2) << std::endl;

	std::cout << "\n";

	// Get Bit
	std::cout << "ba2.GetBit(1): " << ba2.GetBit(1) << std::endl;
	std::cout << "ba2.GetBit(65): " << ba2.GetBit(65) << std::endl;

	ba2.SetBit(65, 1);
	std::cout << "ba2.GetBit(65): " << ba2.GetBit(65) << std::endl;
	std::cout << ba2;

	ba2.FlipAllBits();
	std::cout << ba2;

	ba2.SetBit(64, 1);
	std::cout << "ba2.GetBit(64): " << ba2.GetBit(64) << std::endl;

	ba2.SetBit(65, 0);
	std::cout << "ba2.GetBit(65): " << ba2.GetBit(65) << std::endl;

	std::cout << "\n";

	// Flip Bit
	ba1.SetBit(0, 1);
	std::cout << "ba1.GetBit(0): " << ba1.GetBit(0) << std::endl;
	ba1.FlipBit(0);
	std::cout << "ba1.GetBit(0): " << ba1.GetBit(0) << std::endl;
	ba1.FlipBit(0);
	std::cout << "ba1.GetBit(0): " << ba1.GetBit(0) << std::endl;

	std::cout << "\n";

	ba2.SetBit(30,1 );
	std::cout << ba2;
	std::cout << "ba2.GetBit(30): " << ba2.GetBit(30) << std::endl;

	ba2.FlipBit(30);
	std::cout << ba2;
	std::cout << "ba2.GetBit(30): " << ba2.GetBit(30) << std::endl;

	ba2.FlipBit(30);
	std::cout << ba2;
	std::cout << "ba2.GetBit(30): " << ba2.GetBit(30) << std::endl;

	std::cout << "\n";

	// Flip All
	std::cout << "ba1.GetBit(0): " << ba1.GetBit(0) << std::endl;
	ba1.FlipAllBits();
	std::cout << "ba1.GetBit(0): " << ba1.GetBit(0) << std::endl;
	ba1.FlipAllBits();
	std::cout << "ba1.GetBit(0): " << ba1.GetBit(0) << std::endl;
//

	std::cout << "\n";

	//op[]

	std::cout << "ba1[0]: " << static_cast<const BitArray<1>&>(ba1)[0] << std::endl;
	std::cout << ba1;

	ba1.FlipBit(0);
	std::cout << "ba1[0]: " << static_cast<const BitArray<1>&>(ba1)[0] << std::endl;
	std::cout << ba1;


	std::cout << "ba1: \n" << ba1;
	ba1.FlipAllBits();
	std::cout << ba1;
//
	std::cout << "ba2: \n" << ba2;
	ba2.FlipAllBits();
	std::cout << "ba2: \n" << ba2;
	ba2.FlipAllBits();
	std::cout << "ba2: \n" << ba2;


	return(0);
}
