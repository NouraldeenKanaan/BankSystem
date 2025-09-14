#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


using namespace std;

class clsUpdateClientScreen :protected clsScreen
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

	static void _ReadClientData(clsBankClient& Client)
	{
		cout << "\nEnter First Name : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email : ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone Number : ";
		Client.PhoneNumber = clsInputValidate::ReadString();

		cout << "\nEnter PINCode : ";
		Client.PINCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance : ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();

	}


public:

	static void ShowUpdateClientInfoScreen()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pUpdateClients))
			return;


		_DrawScreenHeader("Update Client Info Screen");


		cout << "\nEnter Account Number ? ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With Account Number [" << AccountNumber << "] Isn't Exist,Enter Another One ? ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClientCard(Client);

		cout << "\nAre You Sure Want To Update This Client ? Y/N ? ";

		char Update = 'n';
		cin >> Update;

		if (Update == 'y' || Update == 'Y')
		{

			cout << "\nUpdate Client Info:\n";
			cout << "___________________________________\n";

			_ReadClientData(Client);

			clsBankClient::enSaveResults SaveResult;

			SaveResult = Client.Save();

			switch (SaveResult)
			{
			case clsBankClient::svFaildEmptyObject:
				cout << "\nError account was not saved because it's Empty";
				break;
			case clsBankClient::svSucceeded:
				cout << "\nClient Updated Successfully :-)";
				_PrintClientCard(Client);
				break;
			case clsBankClient::svFaildAccountNumberExist:
				cout << "\nError account was not saved because it's Empty";
				break;
			}

		}

	}

};

