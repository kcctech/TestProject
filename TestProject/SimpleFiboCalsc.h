#pragma once
#include "IFiboCalc.h"
class SimpleFiboCalsc :
	public IFiboCalc
{
private:
	unsigned long long CurrFiboNum;
	unsigned long long  LastFiboNum;
public:
	SimpleFiboCalsc();
	unsigned long long CalcNextFiboNumber();
	void ResetFiboCalculator();

	~SimpleFiboCalsc();
};

