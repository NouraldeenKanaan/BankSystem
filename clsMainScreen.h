#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsAddNewClientScreen.h"
#include "clsBankClient.h"
#include "clsDeleteClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsClientListScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersMenue.h"
#include "clsLoginScreen.h"
#include "clsUser.h"
#include "clsShowLogInRegisterScreen.h"
#include "clsCurrencyMainScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
	
private:
	
	enum _enMainMenueOptions
	{
		enShowClientList = 1, enAddNewClient = 2, enDeleteClient = 3, enUpdateClient = 4, enFindClient = 5
		, enTransactions = 6, enManageUsers = 7, enLogInRegister = 8, enCurrencyExchange = 9, enLogout = 10
	};

	static _enMainMenueOptions _ReadMainMenueOption()
	{
		cout << "\t\t\t\t" << "    Choose what do you want to do ? [1 To 10] ? ";
		return _enMainMenueOptions(clsInputValidate::ReadShortNumberBetween(1, 10, "\t\t\t\t    Invalid,enter number between 1 and 10 ? "));
	}

	static void _ShowClientListScreen()
	{
		clsClientListScreen::ShowClientListScreen();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientInfoScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientInfoScreen();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsScreen()
	{
		clsTransactionsScreen::ShowTransactionsScreen();
	}

	static void _ShowManageUsersScreen()
	{
		clsManageUsersMenue::ShowManageUsersScreen();
	}
	
	static void _ShowLogInRegisterScreen()
	{
		clsShowLogInRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		clsCurrencyMainScreen::ShowCurrencyMainMenue();
	}

	static void _BackToMainMenue()
	{
		cout << "\n\nPress any key to go back to main menue ...";
		system("pause>0");
		ShowMainMenue();
	}

	static void _PerformMainMenueScreen(_enMainMenueOptions Option)
	{
		switch (Option)
		{
		case clsMainScreen::enShowClientList:
			system("cls");
			_ShowClientListScreen();
			_BackToMainMenue();
			break;
		case clsMainScreen::enAddNewClient:
			system("cls");
			_ShowAddNewClientScreen();
			_BackToMainMenue();
			break;
		case clsMainScreen::enDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_BackToMainMenue();
			break;
		case clsMainScreen::enUpdateClient:
			system("cls");
			_ShowUpdateClientInfoScreen();
			_BackToMainMenue();
			break;
		case clsMainScreen::enFindClient:
			system("cls");
			_ShowFindClientScreen();
			_BackToMainMenue();
			break;
		case clsMainScreen::enTransactions:
			_ShowTransactionsScreen();
			ShowMainMenue();
			break;
		case clsMainScreen::enManageUsers:
			_ShowManageUsersScreen();
			ShowMainMenue();
			break;
		case clsMainScreen::enLogInRegister:
			system("cls");
			_ShowLogInRegisterScreen();
			_BackToMainMenue();
			break;
		case clsMainScreen::enCurrencyExchange:
			_ShowCurrencyExchangeScreen();
			ShowMainMenue();
			break;
		case clsMainScreen::enLogout:
			system("cls");
			break;
		}
	}
	

public:

	static void ShowMainMenue()
	{

		system("cls");
		_DrawScreenHeader("Main Screen");

		cout << "\t\t\t\t" << "==================================================" << endl;
		cout << "\t\t\t\t\t\t" << "    Main Menue" << endl;
		cout << "\t\t\t\t" << "==================================================" << endl;

		cout << "\t\t\t\t" << "    [1]" << " Show Client List." << endl;
		cout << "\t\t\t\t" << "    [2]" << " Add New Client." << endl;
		cout << "\t\t\t\t" << "    [3]" << " Delete Client." << endl;
		cout << "\t\t\t\t" << "    [4]" << " Update Client Info." << endl;
		cout << "\t\t\t\t" << "    [5]" << " Find Client." << endl;
		cout << "\t\t\t\t" << "    [6]" << " Transactions." << endl;
		cout << "\t\t\t\t" << "    [7]" << " Manage Users." << endl;
		cout << "\t\t\t\t" << "    [8]" << " LogIn Register." << endl;
		cout << "\t\t\t\t" << "    [9]" << " Currency Exchange." << endl;
		cout << "\t\t\t\t" << "    [10]" << " Logout." << endl;

		cout << "\t\t\t\t" << "==================================================" << endl;

		_PerformMainMenueScreen(_ReadMainMenueOption());

	}

};

