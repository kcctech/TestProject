#include "stdafx.h"
#include <memory>
#include "../../TestProject/SimpleFiboCalsc.h"


typedef std::unique_ptr<IFiboCalc> FiboCalcClass;

const int MaxIterationsForTest = 35;
const unsigned long long Fibo35 = 14930352;

BOOST_AUTO_TEST_CASE(FiboClassTest)
{
	FiboCalcClass FiboCalc;
	FiboCalc = FiboCalcClass(new SimpleFiboCalsc());
	unsigned long long FiboNum;

	BOOST_CHECK(FiboCalc->CalcNextFiboNumber() == 1);     //testing first 5 fibonacci numbers      

	BOOST_CHECK(FiboCalc->CalcNextFiboNumber() == 2);

	BOOST_CHECK(FiboCalc->CalcNextFiboNumber() == 3);

	BOOST_CHECK(FiboCalc->CalcNextFiboNumber() == 5);

	BOOST_CHECK(FiboCalc->CalcNextFiboNumber() == 8);



	FiboCalc->ResetFiboCalculator();
	BOOST_CHECK(FiboCalc->CalcNextFiboNumber() == 1);	//testing a calculating 35 fibonacci number 

	FiboCalc->ResetFiboCalculator();
	for (int i = 0; i < MaxIterationsForTest; ++i)
	{
		FiboNum = FiboCalc->CalcNextFiboNumber();
	}
	BOOST_CHECK(FiboNum == Fibo35);

}


