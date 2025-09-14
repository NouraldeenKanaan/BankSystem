#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsDeleteUserScreen:protected clsScreen
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

public:

	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("Delete User Screen");

		cout << "\nEnter Username ? ";
		string UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUsername Isn't Exist,Enter Another Username ? ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUserCard(User);

		cout << "\n\nAre You Sure Do You Want To Delete This User ? N/Y ? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (User.Delete())
			{
				cout << "\nUser Deleted Successfully\n";
				_PrintUserCard(User);
			}
			else
			{
				cout << "\nCan't Delete This User";
			}

		}
		else
		{
			cout << "\nOperation Was Cancelled.";
		}

	}

};

