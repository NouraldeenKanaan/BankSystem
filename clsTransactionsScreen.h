#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsWithdrawScreen.h"
#include "clsDepositScreen.h"
#include "clsInputValidate.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsShowTransferLogScreen.h"

using namespace std;

class clsTransactionsScreen :protected clsScreen
{

private:

	enum _enTransactionsScreenOptions {
		trDeposit = 1, trWithdraw = 2, trTotalBalances = 3, trTransfer = 4,
		trTransferLog = 5, trMainScreen = 6
	};

	static _enTransactionsScreenOptions _ReadTransactionsOption()
	{
		cout << "\t\t\t\t" << "    Choose What Do You Want To Do ? [1 To 6] ? ";
		return _enTransactionsScreenOptions(clsInputValidate::ReadShortNumberBetween(1, 6,
			"\t\t\t\t    Wrong Input! Enter Number Between 1 and 6 ? "));
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}
	
	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLog()
	{
		clsShowTransferLogScreen::ShowTransferLogScreen();
	}

	static void _BackToTransactionsMenue()
	{
		cout << "\n\n\nPress any key to go back to transactions menue ...";
		system("pause>0");
		ShowTransactionsScreen();
	}

	static void _PerformTransactionsScreenOptions(_enTransactionsScreenOptions Option)
	{
		switch (Option)
		{
		case clsTransactionsScreen::trDeposit:
			system("cls");
			_ShowDepositScreen();
			_BackToTransactionsMenue();
			break;
		case clsTransactionsScreen::trWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_BackToTransactionsMenue();
			break;
		case clsTransactionsScreen::trTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_BackToTransactionsMenue();
			break;
		case clsTransactionsScreen::trTransfer:
			system("cls");
			_ShowTransferScreen();
			_BackToTransactionsMenue();
			break;
		case clsTransactionsScreen::trTransferLog:
			system("cls");
			_ShowTransferLog();
			_BackToTransactionsMenue();
			break;
		case clsTransactionsScreen::trMainScreen:
			break;
		}
	}

public:


	static void ShowTransactionsScreen()
	{

		system("cls");

		if (!_CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			cout << "\n\n\nPress any key to go back to main menue ...";
			system("pause>0");
			return;
		}
	


		_DrawScreenHeader("Transactions Screen");


		cout << "\t\t\t\t" << "==================================================" << endl;
		cout << "\t\t\t\t\t\t" << " Transactions Menue" << endl;
		cout << "\t\t\t\t" << "==================================================" << endl;

		cout << "\t\t\t\t" << "    [1]" << " Deposit." << endl;
		cout << "\t\t\t\t" << "    [2]" << " Withdraw." << endl;
		cout << "\t\t\t\t" << "    [3]" << " Total Balances." << endl;
		cout << "\t\t\t\t" << "    [4]" << " Transfer." << endl;
		cout << "\t\t\t\t" << "    [5]" << " Transfer Log." << endl;
		cout << "\t\t\t\t" << "    [6]" << " Main Menue." << endl;

		cout << "\t\t\t\t" << "==================================================" << endl;

		_PerformTransactionsScreenOptions(_ReadTransactionsOption());
	}


};