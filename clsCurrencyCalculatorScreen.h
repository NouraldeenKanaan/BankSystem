#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsCurrency.h"

using namespace std;

class clsCurrencyCalculatorScreen:protected clsScreen
{

private:

	static clsCurrency _Currency1()
	{
		cout << "\nPlease Enter Currency1 Code ? ";
		string Currency1Code = clsString::UpperAllString(clsInputValidate::ReadString());

		while (!clsCurrency::IsCurrencyExistByCode(Currency1Code))
		{
			cout << "\nCurrency With Code [" << Currency1Code << "] Isn't Exist,Enter Another Currency Code Please ? ";
			Currency1Code = clsString::UpperAllString(clsInputValidate::ReadString());
		}

		clsCurrency Currency1 = clsCurrency::FindByCode(Currency1Code);

		return Currency1;

	}

	static clsCurrency _Currency2()
	{
		cout << "\nPlease Enter Currency2 Code ? ";
		string Currency2Code = clsString::UpperAllString(clsInputValidate::ReadString());

		while (!clsCurrency::IsCurrencyExistByCode(Currency2Code))
		{
			cout << "\nCurrency With Code [" << Currency2Code << "] Isn't Exist,Enter Another Currency Code Please ? ";
			Currency2Code = clsString::UpperAllString(clsInputValidate::ReadString());
		}

		clsCurrency Currency2 = clsCurrency::FindByCode(Currency2Code);

		return Currency2;
	}

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n\n_________________________\n\n";
		cout << "Country   : " << Currency.Country();
		cout << "\nCode      : " << Currency.CurrencyCode();
		cout << "\nCountry   : " << Currency.CurrencyName();
		cout << "\nRate($)   : " << Currency.Rate();
		cout << "\n\n_________________________\n\n";
	}

	static float _ConvertToDollar(float Amount,clsCurrency Currency)
	{
		return (Amount / Currency.Rate());
	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		

		char Again = 'n';

		do
		{

			system("cls");
			_DrawScreenHeader("Currency Calculator Screen");

			clsCurrency Currency1 = _Currency1();
			clsCurrency Currency2 = _Currency2();

			cout << "\nEnter Amount To Exchange ? ";
			float Amount = clsInputValidate::ReadFloatNumber();

			cout << "\n\nConvert From :";
			_PrintCurrencyCard(Currency1);

			float AmountAfterConvertToUSD = _ConvertToDollar(Amount, Currency1);

			cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = ";
			cout << AmountAfterConvertToUSD << " USD \n";

			if (Currency2.CurrencyCode() != "USD")
			{
				cout << "\n\nConvert From USD To :";
				_PrintCurrencyCard(Currency2);

				float AmountAfterConvertFromUSD = (AmountAfterConvertToUSD * Currency2.Rate());

				cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = ";
				cout << AmountAfterConvertFromUSD << " " << Currency2.CurrencyCode() << endl;

			}

			cout << "\n\nDo You Want To Perform Another Calculation N/Y ? ";
			cin >> Again;

		} while (Again == 'y' || Again == 'Y');

	}

};

