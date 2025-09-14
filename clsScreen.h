#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{

protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t" << "   ____________________________________________";
        cout << "\n\n\t\t\t\t\t\t " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t\t   " << SubTitle;
        }
        cout << "\n\t\t\t\t" << "   ____________________________________________\n\n";
        
        _AddDateAndLoggedInUser();
    }

    static bool _CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermissions(Permission))
        {
            cout << "\t\t\t\t" << "   ____________________________________________";
            cout << "\n\n\t\t\t\t\t" << "Access Denied! Contact To Your Admin\n";
            cout << "\t\t\t\t" << "   ____________________________________________";
            return false;
        }
        else
        {
            return true;
        }
    }

    static void _AddDateAndLoggedInUser(string Username = CurrentUser.UserName)
    {
        cout << "\t\t\t\t" << "      User : " << Username << endl;
        clsDate CurrentDate;
        cout << "\t\t\t\t" << "      Date : " << clsDate::DateToString(clsDate()) << endl << endl;
    }

};

