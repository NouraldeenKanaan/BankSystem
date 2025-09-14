#pragma once

#include <iostream>
using namespace std;

	class clsPerson
	{
	private:

		string _FirstName;
		string _LastName;
		string _FullName;
		string _Email;
		string _Phone;

	public:

		clsPerson(string FirstName, string LastName, string Email, string Phone)
		{
			_FirstName = FirstName;
			_LastName = LastName;
			_Email = Email;
			_Phone = Phone;
		}

		void SitFirstName(string FirstName)
		{
			_FirstName = FirstName;
		}

		string GetFirstName()
		{
			return _FirstName;
		}

		__declspec(property(get = GetFirstName, put = SitFirstName)) string FirstName;

		void SitLastName(string LastName)
		{
			_LastName = LastName;
		}

		string GetLastName()
		{
			return _LastName;
		}

		__declspec(property(get = GetLastName, put = SitLastName)) string LastName;

		string FullName()
		{
			return _FirstName + " " + _LastName;
		}

		void SitEmail(string Email)
		{
			_Email = Email;
		}

		string GetEmail()
		{
			return _Email;
		}

		__declspec(property(get = GetEmail, put = SitEmail)) string Email;

		void SitPhone(string Phone)
		{
			_Phone = Phone;
		}

		string GetPhone()
		{
			return _Phone;
		}

		__declspec(property(get = GetPhone, put = SitPhone)) string PhoneNumber;

	};
