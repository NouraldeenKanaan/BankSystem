#pragma once
#include <iostream>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsAddNewClientScreen :protected clsScreen
{

private:

	static void _ReadNewClientFullData(clsBankClient& Client)
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

	static void ShowAddNewClientScreen()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pAddNewClient))
			return;


		_DrawScreenHeader("Add New Client Screen");

		
		cout << "Enter Account Number ? ";
		string AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With Account Number [" << AccountNumber << "] Already Exist,Enter Another One ? ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClient(AccountNumber);

		_ReadNewClientFullData(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject:
			cout << "\nError,Client Can't Be Save";
			break;
		case clsBankClient::svSucceeded:
			cout << "\nClient Added Successfully ...";
			_PrintClientCard(NewClient);
			break;
		case clsBankClient::svFaildAccountNumberExist:
			cout << "\nError,Client Can't Be Save";
			break;
		}
	}

};

