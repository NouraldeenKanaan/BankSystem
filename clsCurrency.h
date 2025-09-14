#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsString.h"

using namespace std;

class clsCurrency
{

private:

	enum _enCurrencyMode { EmptyMode = 0, UpdateMode = 1 };
	_enCurrencyMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector <string> Data = clsString::Split(Line, Seperator);

		return clsCurrency(_enCurrencyMode::UpdateMode, Data[0], Data[1], Data[2], stod(Data[3]));
	}

	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{

		string stCurrencyRecord = "";

		stCurrencyRecord += Currency.Country() + Seperator;
		stCurrencyRecord += Currency.CurrencyCode() + Seperator;
		stCurrencyRecord += Currency.CurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.Rate());

		return stCurrencyRecord;

	}

	static vector <clsCurrency> _LoadCurrencyDataFromFile()
	{

		vector <clsCurrency> Currencies;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile,Line))
			{
				Currencies.push_back(_ConvertLineToCurrencyObject(Line));
			}

			MyFile.close();
		}
		
		return Currencies;

	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> Data)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line = "";

			for (clsCurrency& C : Data)
			{
				Line = _ConverCurrencyObjectToLine(C);
				MyFile << Line << endl;
			}

			MyFile.close();
		}
	}
	
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(_enCurrencyMode::EmptyMode, "", "", "", 0);
	}

	void _Update()
	{
		vector <clsCurrency> _vCurrencies = _LoadCurrencyDataFromFile();

		for (clsCurrency& Currency : _vCurrencies)
		{
			if (Currency.CurrencyCode() == CurrencyCode())
			{
				Currency = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(_vCurrencies);

	}

public:

	clsCurrency(_enCurrencyMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == _enCurrencyMode::EmptyMode);
	}

	string Country()
	{
		return _Country;
	}
	string CurrencyCode()
	{
		return _CurrencyCode;
	}
	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}
	float Rate()
	{
		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}
	static clsCurrency FindByCountry(string CurrencyCountry)
	{
		CurrencyCountry = clsString::UpperAllString(CurrencyCountry);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.Country()) == CurrencyCountry)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExistByCode(string CurrencyCode)
	{
		clsCurrency C = clsCurrency::FindByCode(CurrencyCode);
		return (!C.IsEmpty());
	}
	static bool IsCurrencyExistByCountry(string CurrencyCountry)
	{
		clsCurrency C = clsCurrency::FindByCountry(CurrencyCountry);
		return (!C.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}

	 float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}
	 float ConvertToOtherCurrency(float Amount, clsCurrency ToCurrency)
	 {
		 return (float)(ConvertToUSD(Amount) * ToCurrency.Rate());
	 }

};

