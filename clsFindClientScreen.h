#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindClientScreen:protected clsScreen
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

	static void ShowFindClientScreen()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pFindClient))
			return;


		_DrawScreenHeader("Find Client Screen");


		cout << "\nEnter Account Number ? ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With Account Number [" << AccountNumber << "] Isn't Exist,Enter Another One ? ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\n\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient Was not Found :-(\n";
		}

		_PrintClientCard(Client);

	}

};

