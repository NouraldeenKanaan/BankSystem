#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsUser.h"

using namespace std;

class clsManageUsersMenue:protected clsScreen
{

private:

	enum _enManageUsersOptions {
		enListUsers = 1, enAddNewUser = 2, DeleteUser = 3,
		UpdateUser = 4, FindUser = 5, ExitScreenBackToMainMenue = 6
	};

	static _enManageUsersOptions _ReadManageUsersOption()
	{
		cout << "\t\t\t\t" << "    Choose What Do You Want To Do ? [1 To 6] ? ";
		return _enManageUsersOptions(clsInputValidate::ReadShortNumberBetween(1,6 ,
			"\t\t\t\t    Wrong Input! Enter Number Between 1 and 6 ? "));
	}

	static void _ShowListUsersScreen()
	{
		clsListUsersScreen::ShowUsersListScreen();
	}

	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _BackToManageUsersMenue()
	{
		cout << "\n\n\nPress any key to go back to manage users menue ...";
		system("pause>0");
		ShowManageUsersScreen();
	}

	static void _PerformManageUsersScreen(_enManageUsersOptions Option)
	{
		switch (Option)
		{
		case clsManageUsersMenue::enListUsers:
			system("cls");
			_ShowListUsersScreen();
			_BackToManageUsersMenue();
			break;
		case clsManageUsersMenue::enAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_BackToManageUsersMenue();
			break;
		case clsManageUsersMenue::DeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_BackToManageUsersMenue();
			break;
		case clsManageUsersMenue::UpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_BackToManageUsersMenue();
			break;
		case clsManageUsersMenue::FindUser:
			system("cls");
			_ShowFindUserScreen();
			_BackToManageUsersMenue();
			break;
		case clsManageUsersMenue::ExitScreenBackToMainMenue:
			break;
		}
	}

public:

	static void ShowManageUsersScreen()
	{

		system("cls");

		if (!_CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			cout << "\n\n\nPress any key to go back to main menue ...";
			system("pause>0");
			return;
		}


		_DrawScreenHeader("Manage Users Screen");


		cout << "\t\t\t\t" << "==================================================" << endl;
		cout << "\t\t\t\t\t\t" << " Manage Users Menue" << endl;
		cout << "\t\t\t\t" << "==================================================" << endl;

		cout << "\t\t\t\t" << "    [1]" << " List Users." << endl;
		cout << "\t\t\t\t" << "    [2]" << " Add New User." << endl;
		cout << "\t\t\t\t" << "    [3]" << " Delete User." << endl;
		cout << "\t\t\t\t" << "    [4]" << " Update User." << endl;
		cout << "\t\t\t\t" << "    [5]" << " Find User." << endl;
		cout << "\t\t\t\t" << "    [6]" << " Main Menue." << endl;

		cout << "\t\t\t\t" << "==================================================" << endl;

		_PerformManageUsersScreen(_ReadManageUsersOption());
	}

};

