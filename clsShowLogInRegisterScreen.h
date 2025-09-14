#pragma once

#include <iostream>
#include "clsScreen.h"
#include <vector>
#include "clsUser.h"
#include <string>
#include <iomanip>
#include "clsUser.h"

using namespace std;

class clsShowLogInRegisterScreen:protected clsScreen
{

private:

	static void _PrintLogInRegister(clsUser::stLogInRegisterRecord LogInRegister)
	{
		cout << "\t| " << left << setw(40) << LogInRegister.DateTime;
		cout << "| " << left << setw(20) << LogInRegister.Username;
		cout << "| " << left << setw(20) << LogInRegister.Password;
		cout << "| " << left << setw(20) << LogInRegister.Permissions;
	}

public:

	static void ShowLoginRegisterScreen()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pShowLogInRegister))
			return;


		vector <clsUser::stLogInRegisterRecord> LogInRegister = clsUser::GetLogInRegisterList();

		string SubTitle = "    (" + to_string(LogInRegister.size()) + ") Record(s)";

		_DrawScreenHeader("LogIn Register Screen",SubTitle);

		cout << "\n\n\t_____________________________________________________________________________________________________\n\n";
		cout << "\t| " << left << setw(40) << "Date/Time";
		cout << "| " << left << setw(20) << "Username";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(20) << "Permissions";
		cout << "\n\t_____________________________________________________________________________________________________\n\n";

		if (LogInRegister.size() == 0)
			cout << "\n\nThere's No LogInRegisters.";

		for (clsUser::stLogInRegisterRecord& Login : LogInRegister)
		{
			_PrintLogInRegister(Login);
			cout << endl;
		}

		cout << "\n\t_____________________________________________________________________________________________________\n\n";

	}

};

