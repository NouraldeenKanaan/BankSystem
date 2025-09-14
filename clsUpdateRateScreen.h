#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsCurrency.h"

using namespace std;

class clsUpdateRateScreen:protected clsScreen
{

private:

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n\n_________________________\n\n";
		cout << "Country   : " << Currency.Country();
		cout << "\nCode      : " << Currency.CurrencyCode();
		cout << "\nCountry   : " << Currency.CurrencyName();
		cout << "\nRate($)   : " << Currency.Rate();
		cout << "\n\n_________________________\n\n";
	}

	static void _ReadNewRate(clsCurrency& Currency)
	{

		float NewRate = 0;

		cout << "\nUpdate Currency Rate : \n";
		cout << "\n_________________________\n\n";
		cout << "Enter New Rate : ";
		
		NewRate = clsInputValidate::ReadFloatNumber();

		Currency.UpdateRate(NewRate);

		cout << "\n\nCurrency Rate Updated Successfully :-)\n";
	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("Update Currency Rate Screen");

		cout << "\nPlease Enter Currency Code ? ";
		string CurrencyCode = clsString::UpperAllString(clsInputValidate::ReadString());

		while (!clsCurrency::IsCurrencyExistByCode(CurrencyCode))
		{
			cout << "\nCurrency With Code [" << CurrencyCode << "] Not Found,Enter Another Code ? ";
			CurrencyCode = clsString::UpperAllString(clsInputValidate::ReadString());
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		cout << "\nCurrency Card : \n";
		_PrintCurrencyCard(Currency);

		cout << "\nAre you sure you want to update the rate of this currency N/Y ? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			_ReadNewRate(Currency);
			_PrintCurrencyCard(Currency);

		}
		else
		{
			cout << "\n\nOperation Cancelled.";
		}

	}

};

