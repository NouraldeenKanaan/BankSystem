#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsUser.h"

using namespace std;

class clsTransferScreen:protected clsScreen
{

private:

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\nClient Card : \n\n";
		cout << "_________________________\n";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc.Number  : " << Client.AccountNumber();
		cout << "\nAcc.Balance : " << Client.AccountBalance;
		cout << "\n_________________________\n";
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screen");

		cout << "\nPlease Enter Account Number To Transfer From ? ";
		string FromAccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(FromAccountNumber))
		{
			cout << "\nClient With Account Number [" << FromAccountNumber << "] Isn't Exist,Enter Another One ? ";
			FromAccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient FromClient = clsBankClient::Find(FromAccountNumber);

		_PrintClientCard(FromClient);

		cout << "\nEnter Account Number To Transfer To ? ";
		string AccountNumberTo = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumberTo))
		{
			cout << "\nClient With Account Number [" << AccountNumberTo << "] Isn't Exist,Enter Another One ? ";
			AccountNumberTo = clsInputValidate::ReadString();
		}

		clsBankClient ToClient = clsBankClient::Find(AccountNumberTo);

		_PrintClientCard(ToClient);

		cout << "\n\nEnter Transfer Amount ? ";
		double TransferAmount = clsInputValidate::ReadDblNumberBetween(1, FromClient.AccountBalance, "\nAmount Exceeds The Available Balance,Enter Another Amount ? ");

		cout << "\nAre You Sure You Want To Perform This Operation ? N/Y ? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			FromClient.Transfer(TransferAmount, ToClient,CurrentUser.UserName);

			cout << "\n\nTransfer Done Successfully .\n";

			_PrintClientCard(FromClient);
			_PrintClientCard(ToClient);
		}
		else
			cout << "\nOperation Cancelled.";

	}

};

