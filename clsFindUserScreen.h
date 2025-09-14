#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindUserScreen:protected clsScreen
{

private:

	static void _PrintUserInfo(clsUser User)
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

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("Find User Screen");

		cout << "\nEnter Username ? ";
		string Username = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(Username))
		{
			cout << "\nUsername Isn't Exist,Enter Another One ? ";
			Username = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(Username);

		cout << "\nUser Found :-)";
		cout << "\n\nUser Card :\n";

		_PrintUserInfo(User);

	}

};

