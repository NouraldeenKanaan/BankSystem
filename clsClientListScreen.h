#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>

using namespace std;

class clsClientListScreen :protected clsScreen
{

private:

	static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout << "\t| " << left << setw(13) << Client.AccountNumber();
		cout << "| " << left << setw(22) << Client.FullName();
		cout << "| " << left << setw(11) << Client.PhoneNumber;
		cout << "| " << left << setw(22) << Client.Email;
		cout << "| " << left << setw(10) << Client.PINCode;
		cout << "| " << left << setw(10) << Client.AccountBalance;
	}

public:

	static void ShowClientListScreen()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pListClients))
			return;


		vector <clsBankClient> vClientsData = clsBankClient::GetClientsList();

		string Subtitle = "(" + to_string(vClientsData.size()) + ") Client(s)";

		_DrawScreenHeader("Client List Screen",Subtitle);

		cout << "\n\n\t_____________________________________________________________________________________________________\n\n";
		cout << "\t| " << left << setw(13) << "Acc.Number";
		cout << "| " << left << setw(22) << "Client Name";
		cout << "| " << left << setw(11) << "Phone";
		cout << "| " << left << setw(22) << "Email";
		cout << "| " << left << setw(10) << "PINCode";
		cout << "| " << left << setw(10) << "Acc.Balance";
		cout << "\n\t_____________________________________________________________________________________________________\n\n";

		if (vClientsData.size() == 0)
		{
			cout << "\n\t\t\t\tNo Client(s) To Show";
		}

		for (clsBankClient& Client : vClientsData)
		{
			_PrintClientRecordLine(Client);
			cout << endl;
		}

		cout << "\n\t_____________________________________________________________________________________________________\n\n";

	}


};

