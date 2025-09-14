#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsShowTransferLogScreen:protected clsScreen
{

private:

	static void _PrintTransferLog(clsBankClient::stTransferLogRecord TransferLog)
	{
		cout << "\t| " << left << setw(27) << TransferLog.DateAndTime;
		cout << "| " << left << setw(11) << TransferLog.FromClient;
		cout << "| " << left << setw(11) << TransferLog.ToClient;
		cout << "| " << left << setw(10) << TransferLog.Amount;
		cout << "| " << left << setw(11) << TransferLog.FromClientBalance;
		cout << "| " << left << setw(11) << TransferLog.ToClientBalance;
		cout << "| " << left << setw(10) << TransferLog.User;
	}

public:

	static void ShowTransferLogScreen()
	{

		vector <clsBankClient::stTransferLogRecord> TransferLogRecord = clsBankClient::GetTransferLogList();

		string Subtitle = "    (" + to_string(TransferLogRecord.size()) + ") Record(s)";

		_DrawScreenHeader("Transfer Log List Screen", Subtitle);

		cout << "\n\t_____________________________________________________________________________________________________\n\n";
		cout << "\t| " << left << setw(27) << "Date/Time";
		cout << "| " << left << setw(11) << "S.Account";
		cout << "| " << left << setw(11) << "D.Account";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(11) << "D.Balance";
		cout << "| " << left << setw(11) << "D.Balance";
		cout << "| " << left << setw(10) << "User";
		cout << "\n\t_____________________________________________________________________________________________________\n\n";

		if (TransferLogRecord.size() == 0)
		{
			cout << "No Transfers To Show";
			return;
		}

		for (clsBankClient::stTransferLogRecord& Record : TransferLogRecord)
		{
			_PrintTransferLog(Record);
			cout << endl;
		}

		cout << "\n\t_____________________________________________________________________________________________________\n\n";

	}

};

