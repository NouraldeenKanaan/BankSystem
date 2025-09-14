#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "clsString.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsTotalBalancesScreen:protected clsScreen
{

private:

	static void _PrintClientTotalBalnces(clsBankClient Client)
	{
		cout << left << "\t\t | " << setw(20) << Client.AccountNumber();
		cout << left << "| " << setw(38) << Client.FullName();
		cout << left << "| " << setw(10) << Client.AccountBalance;
	}

public:

	static void ShowTotalBalancesScreen()
	{
		vector <clsBankClient> vClientsData = clsBankClient::GetClientsList();
		string Subtitle = "    (" + to_string(vClientsData.size()) + ") Client(s).";

		_DrawScreenHeader("Total Balances Screen",Subtitle);

		cout << "\n\t     ________________________________________________________________________________\n\n";
		cout << left << "\t\t | " << setw(20) << "Account Number";
		cout << left << "| " << setw(38) << "Client Name";
		cout << left << "| " << setw(10) << "Balance";
		cout << "\n\t     ________________________________________________________________________________\n\n";

		double SumTotalBalances = 0;

		if (vClientsData.size() == 0)
		{
			cout << "\n\nThere's No Clients To Show.";
		}

		for (clsBankClient& Client : vClientsData)
		{
			_PrintClientTotalBalnces(Client);
			SumTotalBalances += Client.AccountBalance;
			cout << endl;
		}

		cout << "\n\n\t     ________________________________________________________________________________\n\n";

		cout << "\t\t\t\t\tTotal Balances = " << SumTotalBalances << endl;
		cout << "\t\t\t\t(" << clsString::NumberToString(SumTotalBalances) << ")";

	}

};

