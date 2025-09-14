#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsDepositScreen:protected clsScreen
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

	static void ShowDepositScreen()
	{

		_DrawScreenHeader("Deposit Screen");

		cout << "\nEnter Account Number ? ";

		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With Account Number [" << AccountNumber << "] Isn't Exist,Enter Another One ? ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClientCard(Client);

		cout << "\n\nEnter Deposit Amount ? ";

		double DepositAmount = clsInputValidate::ReadDblNumber();

		char Conferm = 'n';

		cout << "\nAre You Sure You Want To Perform This Transaction ? N/Y ? ";
		cin >> Conferm;

		if (Conferm == 'y' || Conferm == 'Y')
		{

			Client.Deposit(DepositAmount);

			cout << "\nAmount Deposited Successfully.\n";

			cout << "New Balance = " << Client.AccountBalance;

		}
		else
			cout << "\nOperation Was Cancelled";

	}

};

