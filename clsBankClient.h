#pragma once

#include <iostream>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include <string>
#include <vector>
#include "clsDate.h"

using namespace std;

class clsBankClient : public clsPerson
{

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2 , DeleteMode = 3 };
	enMode _Mode;

	string _AccountNumber;
	string _PINCode;
	double _AccountBalance;
	bool _MarkToDelete = false;
	
	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vClient = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4],
			vClient[5], stod(vClient[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient Client,string Seperator = "#//#")
	{
		string Line = "";

		Line += Client.FirstName + Seperator;
		Line += Client.LastName + Seperator;
		Line += Client.Email + Seperator;
		Line += Client.PhoneNumber + Seperator;
		Line += Client.AccountNumber() + Seperator;
		Line += Client.PINCode + Seperator;
		Line += to_string(Client.AccountBalance) + Seperator;

		return Line;
	}

	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertLineToTransferLogRecord(string Line, string Seperator = "#//#")
	{
		vector <string> Data = clsString::Split(Line, Seperator);

		stTransferLogRecord TransferLog;

		TransferLog.DateAndTime = Data[0];
		TransferLog.FromClient = Data[1];
		TransferLog.ToClient = Data[2];
		TransferLog.Amount = stod(Data[3]);
		TransferLog.FromClientBalance = stod(Data[4]);
		TransferLog.ToClientBalance = stod(Data[5]);
		TransferLog.User = Data[6];

		return TransferLog;

	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsBankClient> _LoadClientsData()
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile,Line))
			{

				clsBankClient Clients = _ConvertLineToClientObject(Line);

				vClients.push_back(Clients);

			}

			MyFile.close();
		}

		return vClients;

	}

	static void _SaveClientsData(vector <clsBankClient> vClientsdata)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line = "";

			for (clsBankClient& C : vClientsdata)
			{
				if (C._MarkToDelete == false)
				{
					Line = _ConvertClientObjectToLine(C);
					MyFile << Line << endl;
				}
			}

			MyFile.close();
		}

	}

	void _Update()
	{
		vector <clsBankClient> _vClientsData;
		_vClientsData = _LoadClientsData();

		for (clsBankClient& C : _vClientsData)
		{

			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}

		}

		_SaveClientsData(_vClientsData);

	}

	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << DataLine << endl;

			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _RegisterTransferLog(double Amount,clsBankClient ToClient,string Username)
	{
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			string Line = _PreapareTransferRecords(Amount, ToClient, Username);

			MyFile << Line << endl;

			MyFile.close();
		}
	}

	string _PreapareTransferRecords(double Amount,clsBankClient ToClient,string Username,string Seperator = "#//#")
	{
		string Line = "";


		Line += clsDate::DateToString(clsDate()) + " - " + to_string(clsDate::SystemHour()) + ":" +
			to_string(clsDate::SystemMinute()) + ":" + to_string(clsDate::SystemSecond()) + Seperator;

		Line += AccountNumber() + Seperator;
		Line += ToClient.AccountNumber() + Seperator;
		Line += to_string(Amount) + Seperator;
		Line += to_string(AccountBalance) + Seperator;
		Line += to_string(ToClient.AccountBalance) + Seperator;
		Line += Username;

		return Line;
	}

public:

	clsBankClient(enMode Mode,string FirstName, string LastName, string Email, string PhoneNumber, string AccountNumber, string PINCode, double AccountBalance,bool MarkedForDeleted = false)
		:clsPerson(FirstName, LastName, Email, PhoneNumber)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PINCode = PINCode;
		_AccountBalance = AccountBalance;
		_MarkToDelete = MarkedForDeleted;
	}

	struct stTransferLogRecord
	{
		string DateAndTime;
		string FromClient;
		string ToClient;
		double Amount = 0;
		double FromClientBalance = 0;
		double ToClientBalance = 0;
		string User;
	};

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	
	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SitPINCode(string PINCode)
	{
		_PINCode = PINCode;
	}
	string GetPINCode()
	{
		return _PINCode;
	}
	__declspec(property(put = SitPINCode, get = GetPINCode)) string PINCode;

	void SitAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	double GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SitAccountBalance)) double AccountBalance;

	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("CLients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile,Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber,string PINCode)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("CLients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client.PINCode == PINCode)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}   

	enum enSaveResults { svFaildEmptyObject = 0 , svSucceeded = 1 , svFaildAccountNumberExist = 3 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
				return enSaveResults::svFaildEmptyObject;
		}
		case enMode::UpdateMode:
		{

			_Update();
			return enSaveResults::svSucceeded;

		}
		case enMode::AddNewMode:
		{

			if (clsBankClient::IsClientExist(_AccountNumber))
				return enSaveResults::svFaildAccountNumberExist;
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;

			}
		}
		}
	};

	static clsBankClient GetAddNewClient(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> vClientsData = _LoadClientsData();

		for (clsBankClient& C : vClientsData)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkToDelete = true;
				break;
			}
		}

		_SaveClientsData(vClientsData);

		*this = _GetEmptyClientObject();

		return true;
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsData();
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	void Withdraw(double Amount)
	{
		_AccountBalance -= Amount;
		Save();
	}

	void Transfer(double Amount,clsBankClient& DestinationClient,string Username)
	{
		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, Username);
	}

	static vector <stTransferLogRecord> GetTransferLogList()
	{

		vector <stTransferLogRecord> Data;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile,Line))
			{
				Data.push_back(_ConvertLineToTransferLogRecord(Line));
			}

			MyFile.close();
		}

		return Data;
	}
	
};