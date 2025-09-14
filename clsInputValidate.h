#pragma once

#include <iostream>
#include "clsDate.h"

using namespace std;

class clsInputValidate
{

public:

	static bool IsNumberBetween(int NumberToCheck, int From, int To)
	{
		return ((NumberToCheck >= From) && (NumberToCheck <= To));
	}
	static bool IsNumberBetween(double NumberToCheck, double From, double To)
	{
		return ((NumberToCheck >= From) && (NumberToCheck <= To));
	}

	static bool IsDateBetween(clsDate DateToCheck, clsDate From, clsDate To)
	{

		if (clsDate::IsDate1AfterDate2(From, To))
		{
			clsDate::SwapDates(From, To);
			return (clsDate::IsDate1AfterDate2(DateToCheck, From) && clsDate::IsDate1BeforeDate2(DateToCheck, To));
		}
		else
			return (clsDate::IsDate1AfterDate2(DateToCheck, From) && clsDate::IsDate1BeforeDate2(DateToCheck, To));

	}
	
	static short ReadShortNumber(string Message = "Invalid Number,Enter Another Number ? ")
	{
		short Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();

			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << Message;

			cin >> Number;
		}

		return Number;
	}
	static int ReadIntNumber(string Message = "Invalid Number,Enter Another Number ? ")
	{
		int Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();

			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << Message;

			cin >> Number;
		}

		return Number;
	}
	static float ReadFloatNumber(string Message = "Invalid Number,Enter Another Number ? ")
	{
		float Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();

			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << Message ;

			cin >> Number;
		}

		return Number;
	}
	static double ReadDblNumber(string Message = "Invalid Number,Enter Another Number ? ")
	{
		double Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();

			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << Message;

			cin >> Number;
		}

		return Number;
	}

	static string ReadString()
	{
		string S1 = "";

		getline(cin >> ws, S1);
		
		return S1;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Invalid Number,Enter Another Number ? ")
	{
		int Number = ReadIntNumber(ErrorMessage);

		while (Number < From || Number > To)
		{
			cout << ErrorMessage ;
			Number = ReadIntNumber(ErrorMessage);
		}
		
			return Number;

	}
	static short ReadShortNumberBetween(int From, int To, string ErrorMessage = "Invalid Number,Enter Another Number ? ")
	{
		short Number = ReadShortNumber(ErrorMessage);

		while (Number < From || Number > To)
		{
			cout << ErrorMessage;
			Number = ReadShortNumber(ErrorMessage);
		}

		return Number;

	}
	static float ReadFloatNumberBetween(double From, double To, string ErrorMessage = "Invalid Number,Enter Another Number ? ")
	{
		float Number = ReadFloatNumber(ErrorMessage);

		while (Number < From || Number > To)
		{
			cout << ErrorMessage;
			Number = ReadFloatNumber(ErrorMessage);
		}

		return Number;

	}
	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Invalid Number,Enter Another Number ? ")
	{
		double Number = ReadDblNumber(ErrorMessage);

		while (Number < From || Number > To)
		{
			cout << ErrorMessage ;
			Number = ReadDblNumber(ErrorMessage);
		}

		return Number;

	}


};