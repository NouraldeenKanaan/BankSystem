#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsListUsersScreen:protected clsScreen
{

private:

	static void _PrintUserCard(clsUser User)
	{
		cout << "\t| " << left << setw(11) << User.UserName;
		cout << "| " << left << setw(24) << User.FullName();
		cout << "| " << left << setw(11) << User.PhoneNumber;
		cout << "| " << left << setw(22) << User.Email;
		cout << "| " << left << setw(10) << User.Password;
		cout << "| " << left << setw(10) << User.Permissions;
	}

public:

	static void ShowUsersListScreen()
	{
		vector <clsUser> vUsersData = clsUser::GetUsersList();

		string Subtitle = "(" + to_string(vUsersData.size()) + ") Users(s)";

		_DrawScreenHeader("Users List Screen", Subtitle);


		cout << "\n\n\t_____________________________________________________________________________________________________\n\n";
		cout << "\t| " << left << setw(11) << "UserName";
		cout << "| " << left << setw(24) << "Full Name";
		cout << "| " << left << setw(11) << "Phone";
		cout << "| " << left << setw(22) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << "\n\t_____________________________________________________________________________________________________\n\n";

		if (vUsersData.size() == 0)
		{
			cout << "\n\t\t\t\tNo Users(s) To Show";
		}

		for (clsUser& User : vUsersData)
		{
			_PrintUserCard(User);
			cout << endl;
		}

		cout << "\n\t_____________________________________________________________________________________________________\n\n";

		
	}

};

