#ifndef _MDTEST_H_
#define _MDTEST_H_

#include "Test.h"
#include "MemoryFunction.h"

class CMdTest : public CTest
{
public:
						CMdTest();
	virtual				~CMdTest();

	void				Compile(Jitter::CJitter&);
	void				Run();

private:
	struct CONTEXT
	{
#ifdef WIN32
__declspec(align(16))
#else
__attribute__((aligned(16)))
#endif
		uint8			src0[16];
		uint8			src1[16];
		uint8			src2[16];

		uint8			dstMov[16];
		uint8			dstAddB[16];
		uint8			dstAddH[16];
		uint8			dstAddW[16];
		uint8			dstAddWUS[16];
		uint8			dstAddWSS[16];
		uint8			dstCmpEqW[16];

		uint8			dstSrlH[16];
		uint8			dstSrlW[16];
		uint8			dstSraW[16];
		uint8			dstSllW[16];
		uint8			dstSrl256[16];

		uint8			dstPackHB[16];
		uint8			dstPackWH[16];

		uint8			dstUnpackLowerBH[16];
		uint8			dstUnpackLowerHW[16];
		uint8			dstUnpackLowerWD[16];
		uint8			dstUnpackUpperWD[16];
	};

	uint32				ComputeWordUnsignedSaturation(uint32, uint32);
	uint32				ComputeWordSignedSaturation(uint32, uint32);

	CMemoryFunction*	m_function;
};

#endif