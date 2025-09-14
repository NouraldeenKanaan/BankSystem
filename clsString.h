#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString
{
private:

	string _Value;
	short _EncryptionKey = 0;

public:

	clsString()
	{
		_Value = "";
	}
	clsString(string Value)
	{
		_Value = Value;
	}


	void SitValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}
	__declspec	 (property(get = GetValue, put = SitValue)) string Value;

	static void FirstLetterInEachWord(string S1)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < S1.length() ; i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				cout << S1[i] << endl;
			}

			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}
	}
	void FirstLetterInEachWord()
	{
		FirstLetterInEachWord(_Value);
	}

	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}
			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static	string LowerFirstLetterOfEachWord(string S1)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
			{
				S1[i] = tolower(S1[i]);
			}
			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}

		return S1;
	}
	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}

		return S1;
	}
	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	static char InvertLetterCase(char C1)
	{
		return isupper(C1) ? tolower(C1) : toupper(C1);
	}

	static string InvertAllLettersCase(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}
	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	static short Length(string S1)
	{
		return S1.length();
	}
	short Length()
	{
		return _Value.length();
	}

	static short CountLetters(string S1)
	{

		short Counter = 0;

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
				Counter++;
		}

		return Counter;
	}
	short CountLetters()
	{
		return CountLetters(_Value);
	}

	static	short CountCapitalLetters(string S1)
	{
		short Counter = 0;

		for (int i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
    }
	short CountCapitalLetters()	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string S1)
	{
		short Counter = 0;

		for (int i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static short CountSpecificLetter(string S1, char C1, bool MatchCase = true)
	{
		short Counter = 0;

		for (int i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (C1 == S1[i])
				{
					Counter++;
				}
				else
				{
					if (tolower(S1[i]) == tolower(C1))
						Counter++;
				}
			}
			else
			{
				if (C1 == S1[i])
				{
					Counter++;
				}
			}
		}
		return Counter;
	}
	short CountSpecificLetter(char C1, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, C1, MatchCase);
	}

	static bool IsVowel(char C)
	{
		char VowelChars[5] = { 'a','e','i','u','o' };

		for (short i = 0; i < 5; i++)
		{
			if (C == VowelChars[i])
				return true;
		}

		return false;
	}

	static short VowelsCounter(string S1)
	{
		short Counter = 0;

		for (int i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
				Counter++;

		}
		return Counter;
	}
	short VowelsCounter()
	{
		return VowelsCounter(_Value);
	}

	static int CountWords(string S1)
	{
		string Delim = " ";
		int Counter = 0;
		short Pos = 0;
		string Word = "";

		while ((Pos = S1.find(Delim)) != std::string::npos)
		{
			Word = S1.substr(0, Pos);

			if (Word != "")
			{
				Counter++;
			}
			S1.erase(0, Pos + Delim.length());
		}

		if (S1 != "")
		{
			Counter++;
		}

		return Counter;
	}
	int CountWords()
	{
		return CountWords(_Value);
	}

	static vector <string> Split(string S1,string Seperator)
	{
		vector <string> vString;

		short Pos = 0;
		string Word = "";

		while ((Pos = S1.find(Seperator)) != std::string::npos)
		{
			Word = S1.substr(0, Pos);

			//if (Word != "")
			//{
				vString.push_back(Word);
			//}

			S1.erase(0, Pos + Seperator.length());
		
		}

		if (S1 != "")
		{
			vString.push_back(S1);
		}

		return vString;
	}
	vector <string> Split(string Seperator)
	{
		return Split(_Value, Seperator);
	}

	static string TrimLeft(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
				return S1.substr(i, S1.length() - i);
		}
		return "";
	}
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S1)
	{
		for (int i = S1.length(); i >= 0; i--)
		{
			if (S1[i] != ' ')
				return S1.substr(0, i + 1);
		}
		return "";
	}
	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string S1)
	{
		return TrimLeft(TrimRight(S1));
	}
	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string JoinString(vector <string> vString, string Seperator)
	{
		string S1 = "";

		for (string& V : vString)
		{
			S1 += V + Seperator;
		}

		return S1.substr(0, S1.length() - Seperator.length());
	}
	static string JoinString(string arrString[],short Length, string Seperator)
	{
		string S1 = "";

		for (int i = 0; i < Length; i++)
		{
			S1 += arrString[i] + Seperator;
		}

		return S1.substr(0, S1.length() - Seperator.length());
	}

	static string ReverseWordsInString(string S1)
	{
		vector <string> vString = Split(S1, " ");
		string S2 = "";

		vector <string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;

			S2 += *iter + " ";
		}
		return S2.substr(0, S2.length() - 1);
	}
	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{

		vector<string> vString = Split(S1, " ");

		for (string& s : vString)
		{

			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}

			}
			else
			{
				if (LowerAllString(s) == LowerAllString(StringToReplace))
				{
					s = sRepalceTo;
				}

			}

		}

		return JoinString(vString, " ");
	}	
	void ReplaceWord(string StringToReplace,string ReplaceTo)
	{
		_Value = ReplaceWord(_Value, StringToReplace, ReplaceTo);
	}

	static string RemovePunctuations(string S1)
	{
		string S2;

		for (int i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
				S2 += S1[i];
		}
		return S2;
	}
	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}

	static string NumberToString(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "","one","Two","Three","Four","Five","Six","Seven","Eight","Nine",
			"Ten","Eleven","Twelve","thirteen","Fourteen","Fiveteen","Sixteen","Seventeen",
			"Eighteen","Nineteen" };

			return arr[Number] + " ";

		}
		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Fourty","Fivety","Sixty","Seventy","Eighty","Ninty" };
			return arr[Number / 10] + " " + NumberToString(Number % 10);
		}
		if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + NumberToString(Number % 100);
		}
		if (Number >= 200 && Number <= 999)
		{
			return NumberToString(Number / 100) + "Hundreds " + NumberToString(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToString(Number % 1000);
		}
		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToString(Number / 1000) + "Thousands " + NumberToString(Number & 1000);
		}
		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + NumberToString(Number % 1000000);
		}
		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToString(Number / 1000000) + "Millions " + NumberToString(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + NumberToString(Number % 1000000000);
		}
		else
		{
			return NumberToString(Number / 1000000000) + " Billions " + NumberToString(Number % 1000000000);
		}

	}

	static string Encrypt(string S1,short EncryptionKey)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = char(S1[i] + EncryptionKey);
		}
		return S1;
	}
	void Encrypt(short EncryptionKey)
	{
		_EncryptionKey = EncryptionKey;
		_Value = Encrypt(_Value, _EncryptionKey);
	}

	static string Decryption(string S1, short EncryptionKey)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = char(S1[i] - EncryptionKey);
		}
		return S1;
	}
	void Decryption()
	{
		_Value = Decryption(_Value,_EncryptionKey);
	}

};