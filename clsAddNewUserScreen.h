#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsAddNewUserScreen:protected clsScreen
{

private:

	static void _ReadNewUserData(clsUser& User)
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

public:

	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("Add New User Screen");

		cout << "\nPlease Enter UserName ? ";
		string UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUsername Is Already Used,Enter Another One ? ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadNewUserData(NewUser);

		clsUser::enSaveResults SaveResult;
		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::svFaildEmptyObject:
			cout << "\nError,You Can't Add Empty User.";
			break;
		case clsUser::svSucceeded:
			cout << "\nUser Added Successfullly :-)";
			_PrintUserCard(NewUser);
			break;
		case clsUser::svFaildUserNameExist:
			cout << "\nError,You Can't Add User Exist.";
			break;
		}

	}

};

