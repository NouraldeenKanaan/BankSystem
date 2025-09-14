#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <vector>

using namespace std;

class clsListCurrenciesScreen:protected clsScreen
{

private:

	static void _PrintCurrencyData(clsCurrency Currency)
	{
		cout << "\t| " << left << setw(28) << Currency.Country();
		cout << "| " << left << setw(16) << Currency.CurrencyCode();
		cout << "| " << left << setw(40) << Currency.CurrencyName();
		cout << "| " << left << setw(17) << Currency.Rate();
	}

public:

	static void ShowListCurrenciesScreen()
	{
		vector <clsCurrency> vCurrenciesList = clsCurrency::GetCurrenciesList();

		string Subtitle = "  (" + to_string(vCurrenciesList.size()) + ") Currency";

		_DrawScreenHeader("List Currencies Screen",Subtitle);

		cout << "\n\n\t_____________________________________________________________________________________________________\n\n";

		cout << "\t| " << left << setw(28) << "Country";
		cout << "| " << left << setw(16) << "Currency Code";
		cout << "| " << left << setw(40) << "Currency Name";
		cout << "| " << left << setw(17) << "Rate/($)";

		cout << "\n\t_____________________________________________________________________________________________________\n\n";

		if (vCurrenciesList.size() == 0)
		{
			cout << "\nThere's no currencis to show";
			return;
		}

		for (clsCurrency& Currency : vCurrenciesList)
		{
			_PrintCurrencyData(Currency);
			cout << endl;
		}

		cout << "\n\t_____________________________________________________________________________________________________\n\n";

	}

};

