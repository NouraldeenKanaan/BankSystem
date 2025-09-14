#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsUpdateUserScreen:protected clsScreen
{

private:

	static void _PrintUserCard(clsUser User)
	{
		cout << "\n_________________________________________________";
		cout << "\nFirst Name  : " << User.FirstName;
		cout << "\nLast Name   : " << User.LastName;
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.PhoneNumber;
		cout << "\nUsername    : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n_________________________________________________";
	}

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter First Name : ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name : ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email : ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone : ";
		User.PhoneNumber = clsInputValidate::ReadString();

		cout << "\nEnter Password : ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter  Permissions : \n\n";
		User.Permissions = _ReadPermissionsToSit();
	}

	static int _ReadPermissionsToSit()
	{
		int Permissions = 0;
		char Access = 'n';

		cout << "Do You Want To Give Full Access ? N/Y ? ";
		cin >> Access;

		if (Access == 'y' || Access == 'Y')
		{
			return -1;
		}

		cout << "\n\nDo You Want To Give Access To : \n";

		cout << "\nShow Clients List ? N/Y ? ";
		cin >> Access;

		if (Access == 'y' || Access == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Clients ? N/Y ? ";
		cin >> Access;

		if (Access == 'y' || Access == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client ? N/Y ? ";
		cin >> Access;

		if (Access == 'y' || Access == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client ? N/Y ? ";
		cin >> Access;

		if (Access == 'y' || Access == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}

		cout << "\nFind Client ? N/Y ? ";
		cin >> Access;

		if (Access == 'y' || Access == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions Menue ? N/Y ? ";
		cin >> Access;

		if (Access == 'y' || Access == 'Y')
		{
			Permissions += clsUser::enPermissions::pTranactions;
		}

		cout << "\nManage Users Menue ? N/Y ? ";
		cin >> Access;

		if (Access == 'y' || Access == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nShow LogIn Register Screen ? N/Y ? ";
		cin >> Access;

		if (Access == 'y' || Access == 'Y')
		{
			Permissions += clsUser::enPermissions::pShowLogInRegister;
		}


		return Permissions;
	}

public:

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("Update User Screen");

		cout << "\nPlease Enter Usrename ? ";
		string Username = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(Username))
		{
			cout << "\nUsername Isn't Exist,Enter Another One ? ";
			Username = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(Username);

		_PrintUserCard(User);

		cout << "\n\nAre You Sure Do You To Update This User Info ? N/Y ? ";
		
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			cout << "\n\nUpdate User Info :\n\n";

			_ReadUserInfo(User);

			clsUser::enSaveResults SaveResult;

			SaveResult = User.Save();

			switch (SaveResult)
			{
			case clsUser::svFaildEmptyObject:
				break;
			case clsUser::svSucceeded:
				cout << "\n\nUser Updated Successfully :-)";
				_PrintUserCard(User);
				break;
			case clsUser::svFaildUserNameExist:
				break;
			}
		}
		else
		{
			cout << "\nThe Operation Was Cancelled";
		}

	}

};

