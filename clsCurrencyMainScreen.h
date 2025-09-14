#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyMainScreen:protected clsScreen
{

private:

	enum _enCurrencyExchangeOptions
	{
		enListCurrencies = 1, enFindCurrency = 2, enUpdateRate = 3, enCurrencyCalculator = 4, enMainMenue = 5
	};

	static _enCurrencyExchangeOptions _ReadCurrencyExchangeOption()
	{
		cout << "\t\t\t\t" << "    Choose What Do You Want To Do ? [1 To 5] ? ";
		return _enCurrencyExchangeOptions(clsInputValidate::ReadShortNumberBetween(1, 5,
			"\t\t\t\t    Wrong Input! Enter Number Between 1 and 5 ? "));
	}

	static void _ShowListCurrenciesScreen()
	{
		clsListCurrenciesScreen::ShowListCurrenciesScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		clsUpdateRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _BackToCurrencyExchangeMenue()
	{
		cout << "\n\n\n\nPress any key to go back to currency exchange menue ...";
		system("pause>0");
		ShowCurrencyMainMenue();
	}

	static void _PerformCurrencyExchangeMenue(_enCurrencyExchangeOptions Option)
	{
		switch (Option)
		{
		case clsCurrencyMainScreen::enListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_BackToCurrencyExchangeMenue();
			break;
		case clsCurrencyMainScreen::enFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_BackToCurrencyExchangeMenue();
			break;
		case clsCurrencyMainScreen::enUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_BackToCurrencyExchangeMenue();
			break;
		case clsCurrencyMainScreen::enCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_BackToCurrencyExchangeMenue();
			break;
		case clsCurrencyMainScreen::enMainMenue:
			break;
		}
	}

public:

	static void ShowCurrencyMainMenue()
	{
		system("cls");

		_DrawScreenHeader("Currency Exchange Main Screen");


		cout << "\t\t\t\t" << "==================================================" << endl;
		cout << "\t\t\t\t\t\t" << "Currency Exchange Menue" << endl;
		cout << "\t\t\t\t" << "==================================================" << endl;

		cout << "\t\t\t\t" << "    [1]" << " List Currencies." << endl;
		cout << "\t\t\t\t" << "    [2]" << " Find Currency." << endl;
		cout << "\t\t\t\t" << "    [3]" << " Update Rate." << endl;
		cout << "\t\t\t\t" << "    [4]" << " Currency Calculator." << endl;
		cout << "\t\t\t\t" << "    [5]" << " Main Menue." << endl;

		cout << "\t\t\t\t" << "==================================================" << endl;

		_PerformCurrencyExchangeMenue(_ReadCurrencyExchangeOption());

	}

};