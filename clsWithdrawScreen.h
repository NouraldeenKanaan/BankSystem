#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsWithdrawScreen:protected clsScreen
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

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("Withdraw Screen");

		cout << "\nEnter Account Number ? ";

		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With Account Number [" << AccountNumber << "] Isn't Exist,Enter Another One ? ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClientCard(Client);

		cout << "\n\nEnter Withdraw Amount ? ";

		double WithdrawAmount = clsInputValidate::ReadDblNumber();

		while(Client.AccountBalance < WithdrawAmount)
		{
			cout << "\n\nYou Cant't Withdraw More Than Your Balance,You Can Until : " << Client.AccountBalance;
			cout << "\n\nEnter Another Withdraw Amount ? ";
			WithdrawAmount = clsInputValidate::ReadDblNumber();
		}

		char Conferm = 'n';

		cout << "\nAre You Sure You Want To Perform This Transaction ? N/Y ? ";
		cin >> Conferm;

		if (Conferm == 'y' || Conferm == 'Y')
		{
			Client.Withdraw(WithdrawAmount);
			cout << "\n\nThis Transaction Perform Successfully";
			cout << "\nYour New Balance = " << Client.AccountBalance;
		}
		else
			cout << "\n\nOperation Was Cancelled";

	}

};