#include "SimpleFiboCalsc.h"
#include <limits>
#include <stdexcept>

SimpleFiboCalsc::SimpleFiboCalsc()
{
	ResetFiboCalculator();
}

unsigned long long SimpleFiboCalsc::CalcNextFiboNumber() 
{
	long long AuxVariable;
	
	if ((std::numeric_limits<unsigned long long>::max() - CurrFiboNum) < LastFiboNum) throw std::runtime_error("unsigned long long overflow is detected!");
	
	AuxVariable = CurrFiboNum;
	CurrFiboNum = CurrFiboNum + LastFiboNum;
	LastFiboNum = AuxVariable;
	return CurrFiboNum;
}

void SimpleFiboCalsc::ResetFiboCalculator()
{
	CurrFiboNum = 1;
	LastFiboNum = 0;
}


SimpleFiboCalsc::~SimpleFiboCalsc()
{
}
