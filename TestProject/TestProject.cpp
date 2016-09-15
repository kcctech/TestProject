// TestProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <memory>
#include "SimpleFiboCalsc.h"
#include <boost/format.hpp>
#include <boost/chrono.hpp>

typedef std::unique_ptr<IFiboCalc> FiboCalcClass;

int main()
{
	using namespace std;
	int FiboNumCnt;
	FiboCalcClass FiboCalculator;
	FiboCalculator = FiboCalcClass(new SimpleFiboCalsc());
	std::cout << "Type fibo digits count:" << endl;
	std::cin >> FiboNumCnt;
	unsigned long long CurrFiboNum = 1;
	unsigned long long  LastFiboNum = 0, AuxVariable;

	boost::chrono::system_clock::time_point BegTimePoint = boost::chrono::system_clock::now();

	FiboCalculator->ResetFiboCalculator();
	try
	{
		for (int i = 0; i < FiboNumCnt; i++)
		{
			std::cout << "Fibo[" << (i + 1) << "]=" << FiboCalculator->CalcNextFiboNumber() << endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << endl;
	}

	boost::chrono::system_clock::time_point EndTimePoint = boost::chrono::system_clock::now();

	boost::chrono::duration<double> ExecDuration = EndTimePoint - BegTimePoint;

	auto MillisecDuration = boost::chrono::duration_cast<boost::chrono::milliseconds>(ExecDuration);

	std::cout << "Time of execution = " << MillisecDuration << endl;

	string ToInputWait;
	std::cin >> ToInputWait;
	return 0;
}

