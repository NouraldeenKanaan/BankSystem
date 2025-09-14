#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsString.h"

using namespace std;

class clsFindCurrencyScreen:protected clsScreen
{

private:

	enum _enFindBy
	{
		enCode = 1, enCountry = 2
	};

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n\n_________________________\n\n";
		cout << "Country   : " << Currency.Country();
		cout << "\nCode      : " << Currency.CurrencyCode();
		cout << "\nCountry   : " << Currency.CurrencyName();
		cout << "\nRate($)   : " << Currency.Rate();
		cout << "\n\n_________________________\n\n";
	}

	static void _FindByCurrencyCode()
	{
		cout << "\nEnter Currency Code ? ";
		string CurrencyCode = clsString::UpperAllString(clsInputValidate::ReadString());

		while (!clsCurrency::IsCurrencyExistByCode(CurrencyCode))
		{
			cout << "\nCurrency " << CurrencyCode << " Not Found,Try Another One ? ";
			CurrencyCode = clsString::UpperAllString(clsInputValidate::ReadString());
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		cout << "\nCurrency Founded :-)";
		_PrintCurrencyCard(Currency);

	}

	static void _FindByCurrencyName()
	{
		cout << "\nEnter Currency Country ? ";
		string CurrencyCountry = clsString::UpperAllString(clsInputValidate::ReadString());

		while (!clsCurrency::IsCurrencyExistByCountry(CurrencyCountry))
		{
			cout << "\nCurrency " << CurrencyCountry << " Not Found,Try Another One ? ";
			CurrencyCountry = clsString::UpperAllString(clsInputValidate::ReadString());
		}

		clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCountry);

		cout << "\nCurrency Founded :-)";
		_PrintCurrencyCard(Currency);
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen");

		cout << "\nFind By : [1] Code Or [2] Country ? ";
		_enFindBy Answer = _enFindBy(clsInputValidate::ReadShortNumberBetween(1, 2));

		switch (Answer)
		{
		case clsFindCurrencyScreen::enCode:
			_FindByCurrencyCode();
			break;
		case clsFindCurrencyScreen::enCountry:
			_FindByCurrencyName();
			break;
		}

	}

};

