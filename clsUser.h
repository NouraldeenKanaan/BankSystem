#pragma once

#include <iostream>
#include "clsPerson.h"
#include <vector>
#include <string>
#include "clsString.h"
#include <fstream>
#include "clsDate.h"

using namespace std;

class clsUser:public clsPerson
{

private:

	enum _enMode { enEmptyMode = 0, enUpdateMode = 1, enAddNewMode = 2, enDeleteMode = 3 };
	_enMode _Mode;

	string _UserName;
	string _Password;
	int _Permissions ;
	bool _MarkToDelete = false;

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector <string> vUsersData = clsString::Split(Line, Seperator);

		return clsUser(_enMode::enUpdateMode, vUsersData[0], vUsersData[1], vUsersData[2], vUsersData[3],
			vUsersData[4], clsString::Decryption(vUsersData[5],3), stoi(vUsersData[6]));
	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{
		string Line = "";

		Line += User.FirstName + Seperator;
		Line += User.LastName + Seperator;
		Line += User.Email + Seperator;
		Line += User.PhoneNumber + Seperator;
		Line += User.UserName + Seperator;
		Line += clsString::Encrypt(User.Password, 3) + Seperator;
		Line += to_string(User.Permissions);

		return Line;

	}

	struct stLogInRegisterRecord;
	static stLogInRegisterRecord _ConvertLineToLoginRegisterRecord(string Line, string Seperator = "/##/")
	{
		stLogInRegisterRecord LogInRegisterRecord;

		vector <string> Data = clsString::Split(Line,Seperator);

		LogInRegisterRecord.DateTime = Data[0];
		LogInRegisterRecord.Username = Data[1];
		LogInRegisterRecord.Password = clsString::Decryption(Data[2], 3);
		LogInRegisterRecord.Permissions = stoi(Data[3]);

		return LogInRegisterRecord;
	}

	static vector <clsUser> _LoadUsersDataFromFile()
	{
		vector <clsUser> vUsersData;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile,Line))
			{
				vUsersData.push_back(_ConvertLineToUserObject(Line));
			}

			MyFile.close();
		}
		return vUsersData;
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(_enMode::enEmptyMode, "", "", "", "", "", "", 0);
	}

	void _SaveUserObjectToFile(vector <clsUser> vUsersData)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line = "";

			for (clsUser& User : vUsersData)
			{
				if (User._MarkToDelete == false)
				{
					Line = _ConvertUserObjectToLine(User);
					MyFile << Line << endl;
				}
			}

			MyFile.close();
		}

	}
	
	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::app | ios::out);

		if (MyFile.is_open())
		{
			
			MyFile << DataLine << endl;

			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	void _Update()
	{
		vector <clsUser> vUsersData = _LoadUsersDataFromFile();

		for (clsUser& User : vUsersData)
		{
			if (User.UserName == _UserName)
			{
				User = *this;
				break;
			}
		}
		_SaveUserObjectToFile(vUsersData);
	}

	string _PreapareLogInRecord(string Seperator = "/##/")
	{
		string Line = "";


		Line += clsDate::DateToString(clsDate()) + " - " + to_string(clsDate::SystemHour()) + ":" +
			to_string(clsDate::SystemMinute()) + ":" + to_string(clsDate::SystemSecond()) + Seperator;

		Line += UserName + Seperator;
		Line += clsString::Encrypt(Password, 3) + Seperator;
		Line += to_string(Permissions);

		return Line;

	}

public:

	enum enPermissions
	{
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pShowLogInRegister = 128
	};

	struct stLogInRegisterRecord
	{
		string DateTime;
		string Username;
		string Password;
		int Permissions = 0;
	};

	clsUser(_enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
    }

	bool IsEmpty()
	{
		return (_Mode == _enMode::enEmptyMode);
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	void SitUserName(string UserName)
	{
		_UserName = UserName;
	}
	string GetUserName()
	{
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = SitUserName)) string UserName;
	
	void SitPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SitPassword)) string Password;

	void SitPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SitPermissions)) int Permissions;
	
	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile,Line))
			{

				clsUser User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}

			}

			MyFile.close();
		}

		return _GetEmptyUserObject();

	}
	static clsUser Find(string UserName,string Password)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{

				clsUser User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}

			}

			MyFile.close();
		}

		return _GetEmptyUserObject();

	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserNameExist = 3 };

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(_enMode::enAddNewMode, "", "", "", "", UserName, "", 0);
	}

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsUser::enEmptyMode:

			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}

			break;
		case clsUser::enUpdateMode:

			_Update();
			return enSaveResults::svSucceeded;

			break;
		case clsUser::enAddNewMode:

			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFaildUserNameExist;
			}
			else
			{
				_AddNew();
				_Mode = _enMode::enUpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
	}

	bool Delete()
	{
		vector <clsUser> vUsersData = _LoadUsersDataFromFile();

		for (clsUser& User : vUsersData)
		{
			if (User.UserName == _UserName)
			{
				User._MarkToDelete = true;
				break;
			}
		}

		_SaveUserObjectToFile(vUsersData);

		*this = _GetEmptyUserObject();

		return true;

	}

	bool CheckAccessPermissions(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;

		if ((Permission & this->Permissions) == Permission)
			return true;
		else
			return false;
	};

	void RegisterLogIn()
	{
		fstream MyFile;
		MyFile.open("LogInRegister.txt", ios::app | ios::out);

		if (MyFile.is_open())
		{
			string Line = _PreapareLogInRecord();

			MyFile << Line << endl;

			MyFile.close();
		}

	}

	static vector <stLogInRegisterRecord> GetLogInRegisterList()
	{
		vector <stLogInRegisterRecord> vLoginRegister;

		fstream MyFile;
		MyFile.open("LogInRegister.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile,Line))
			{

				vLoginRegister.push_back(_ConvertLineToLoginRegisterRecord(Line));

			}

			MyFile.close();
		}
		return vLoginRegister;
	}

};

