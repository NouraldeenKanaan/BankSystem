#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
{

private:

	static void _PrintClientCard(clsBankClient Client)
	{

		cout << "\nClient Card : ";
		cout << "\n___________________________________________";
		cout << "\nFirstName     : " << Client.FirstName;
		cout << "\nLastName      : " << Client.LastName;
		cout << "\nFull Name     : " << Client.FullName();
		cout << "\nEmail         : " << Client.Email;
		cout << "\nPhone         : " << Client.PhoneNumber;
		cout << "\nAcc. Number   : " << Client.AccountNumber();
		cout << "\nPassword      : " << Client.PINCode;
		cout << "\nAcc. Balance  : " << Client.AccountBalance;
		cout << "\n___________________________________________\n\n\n";

	}



public:

	static void ShowDeleteClientScreen()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pDeleteClient))
			return;


		_DrawScreenHeader("Delete Client Screen");


		cout << "\n\nEnter Account Number ? ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With Account Number [" << AccountNumber << "] Isn't Exist,Enter Another One ? ";	
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient ClientWantToDelete = clsBankClient::Find(AccountNumber);
		
		_PrintClientCard(ClientWantToDelete);

		cout << "\nAre You Sure Want To Delete This Client ? N/Y ? ";

		char Delete = 'n';
		cin >> Delete;

		if (Delete == 'Y' || Delete == 'y')
		{
			if (ClientWantToDelete.Delete())
			{
				cout << "\nClient Deleted Successfully :-) ";
				_PrintClientCard(ClientWantToDelete);
			}
			else
				cout << "\nError Client Wasn't Deleted";

		}

	}

};

