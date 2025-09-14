#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsUser.h"
#include "clsDate.h"


using namespace std;

class clsLoginScreen:protected clsScreen
{
	
private:

	static bool _Login()
	{
		bool LoginFaild = false;
		short FaildTrials = 0;
		string Username, Password;

		do
		{

			if (LoginFaild)
			{
				FaildTrials++;

				cout << "\n\nInvalid Username/Password\n";
				cout << "You Have " << (3 - FaildTrials) << " Trial(s) To Login\n\n";
			}

			if (FaildTrials == 3)
			{
				cout << "\n\nYou are locked After 3 Faild Trials .\n";
				return false;
			}

			cout << "\nEnter Username : ";
			cin >> Username;

			cout << "Enter Password : ";
			cin >> Password;
			
			CurrentUser = clsUser::Find(Username, Password);

			LoginFaild = CurrentUser.IsEmpty();


		} while (LoginFaild);

		CurrentUser.RegisterLogIn();

		clsMainScreen::ShowMainMenue();
		return true;
    }

public:

	static bool ShowLoginScreen()
	{
		_DrawScreenHeader("Login Screen");
		return _Login();
	}

};

