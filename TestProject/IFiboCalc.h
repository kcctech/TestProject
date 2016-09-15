#pragma once
class IFiboCalc
{
public:
	IFiboCalc() {};
	unsigned long long virtual CalcNextFiboNumber() = 0;
	void virtual ResetFiboCalculator() = 0;
	virtual ~IFiboCalc() {};
};

