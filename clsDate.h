#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
#include <string>
#include "clsString.h"

using namespace std;

class clsDate
{

private:

	short _Day;
	short _Month;
	short _Year;

public:


	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}
	clsDate(string sDate)
	{
		vector <string> vDate;
		vDate = clsString::Split(sDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}
	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}
	clsDate(short DateOrderInYear, short Year)
	{
		clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);

		_Day = Date1.Day;
		_Month = Date1.Month;
		_Year = Date1.Year;
	}



	void SitDay(short Day)
	{
		_Day = Day;
	}
	short GetDay()
	{
		return _Day;
	}
	__declspec(property(get = GetDay, put = SitDay)) short Day;

	void SitMonth(short Month)
	{
		_Month = Month;
	}
	short GetMonth()
	{
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SitMonth)) short Month;

	void SitYear(short Year)
	{
		_Year = Year;
	}
	short GetYear()
	{
		return _Year;
	}
	__declspec(property(get = GetYear, put = SitYear)) short Year;


	static string DateToString(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	} 
	string DateToString()
	{
		return DateToString(*this);
	}

	void Print()
	{
		cout << DateToString() << endl;
	}

	static clsDate GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year;

		Day = now->tm_mday;
		Month = now->tm_mon + 1;
		Year = now->tm_year + 1900;

		return clsDate(Day, Month, Year);
	}

	static	bool IsValidDate(clsDate Date)
	{
		if (Date.Day < 1 || Date.Day > 31)
			return false;

		if (Date.Month < 1 || Date.Month > 12)
			return false;

		if (Date.Month == 2)
		{
			if (IsLeapYear(Date.Year))
			{
				if (Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day > 28)
					return false;
			}
		}

		short MonthDays = NumberOfDaysInAMonth(Date.Month,Date.Year);

		if (Date.Day > MonthDays)
			return false;


		return true;
    }
	bool IsValidDate()
	{
		return IsValidDate(*this);
	}

	static bool IsLeapYear(short Year)
	{
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}
	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static short NumberOfDaysInAYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}
	short NumberOfDaysInAYear()
	{
		return NumberOfDaysInAYear(_Year);
	}

	static short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}
	short NumberOfHoursInAYear()
	{
		return NumberOfHoursInAYear(_Year);
	}

	static int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}
	int NumberOfMinutesInAYear()
	{
		return NumberOfMinutesInAYear(_Year);
	}

	static int NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}
	int NumberOfSecondsInAYear()
	{
		return NumberOfSecondsInAYear(_Year);
	}

	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month > 12)
			return 0;

		short MonthsDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : MonthsDays[Month - 1];
	}
	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Month, _Year);
	}

	static short NumberOfHoursInAMonth(short Month, short Year)
	{
		return NumberOfDaysInAMonth(Month, Year) * 24;
	}
	short NumberOfHoursInAMonth()
	{
		return NumberOfHoursInAMonth(_Month, _Year);
	}

	static int NumberOfMinutesInAMonth(short Month, short Year)
	{
		return NumberOfHoursInAMonth(Month, Year) * 60;
	}
	int NumberOfMinutesInAMonth()
	{
		return NumberOfMinutesInAMonth(_Month, _Year);
	}

	static int NumberOfSecondsInAMonth(short Month, short Year)
	{
		return NumberOfMinutesInAMonth(Month, Year) * 60;
	}
	int NumberOfSecondsInAMonth()
	{
		return NumberOfSecondsInAMonth(_Month, _Year);
	}

	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(_Day, _Month, _Year);
	}

	static string DayShortName(short DayOfWeekInOrder)
	{
		string shortName[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return shortName[DayOfWeekInOrder];
	}
	static string DayShortName(short Day,short Month,short Year)
	{
		string shortName[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return shortName[DayOfWeekOrder(Day,Month,Year)];
	}
	string DayShortName()
	{
		string shortName[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return shortName[DayOfWeekOrder(_Day, _Month,_Year)];
	}

	static string MonthShortName(short MonthNumber)
	{
		string MonthsShortN[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return MonthsShortN[MonthNumber - 1];
	}
	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	static void MonthCalendar(short Month,short Year)
	{
		cout << endl << "  _______________" << MonthShortName(Month) << "_______________" << endl << endl;
		cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat  " << endl;

		short NumberOfDays = NumberOfDaysInAMonth(Month,Year);
		short Current = DayOfWeekOrder(1,Month,Year);

		short i ;

		for (i = 0; i < Current; i++)
		{
			printf("     ");
		}

		for (short j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);
			
			if (++i == 7)
			{
				i = 0;
				cout << endl;
			}
		}
		printf("\n  _________________________________\n");
	}
	 void MonthCalendar()
	{
		return MonthCalendar(_Month,_Year);
	}

	 static void YearCalendar(short Year)
	 {
		 printf("\n  _________________________________\n\n");
		 printf("           Calendar - %d", Year);
		 printf("\n  _________________________________\n");

		 for (short i = 1; i <= 12; i++)
		 {
			 MonthCalendar(i,Year);
		 }

	 }
	 void YearCalendar()
	 {
		 return YearCalendar(_Year);
	 }

	 static short DaysFromTheBeginingOfTheYear(short Day,short Month,short Year)
	 {
		 short TotalDays = 0;

		 for (short i = 1; i <Month; i++)
		 {
			 TotalDays += NumberOfDaysInAMonth(i, Year);
		 }

		 TotalDays += Day;

		 return TotalDays;
	 }
	 short DaysFromTheBeginingOfTheYear()
	 {
		 return DaysFromTheBeginingOfTheYear(_Day,_Month,_Year);
	 }

	 static clsDate GetDateFromDayOrderInYear(short DateOrderInYear,short sYear)
	 {
		 clsDate Date;

		 short RemainingDays = DateOrderInYear;
		 short MonthDays = 0;

		 Date.Year = sYear;
		 Date.Month = 1;

		 while (true)
		 {
			 MonthDays = NumberOfDaysInAMonth(Date.Month,sYear);

			 if (RemainingDays > MonthDays)
			 {
				 RemainingDays -= MonthDays;
				 Date.Month++;
			 }
			 else
			 {
				 Date.Day = RemainingDays;
				 break;
			 }

		 }
		 return Date;
	 }
	 
	 void AddDays(short DaysToAdd)
	 {
		 short RemainingDays = DaysFromTheBeginingOfTheYear(_Day, _Month, _Year) + DaysToAdd;
		 short MonthDays = 0;

		 _Month = 1;

		 while (true)
		 {
			 MonthDays = NumberOfDaysInAMonth(_Month, _Year);

			 if (RemainingDays > MonthDays)
			 {
				 RemainingDays -= MonthDays;
				 _Month++;

				 if (_Month > 12)
				 {
					 _Month = 1;
					 _Year++;

				 }
			 }
			 else
			 {
				 _Day = RemainingDays;
				 break;
			 }

		 }
	 }

	 static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	 {
		 return
			 Date1.Year < Date2.Year ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true :
				 Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false) : false);
	 }
	 bool IsDate1BeforeDate2(clsDate Date2)
	 {
		 return IsDate1BeforeDate2(*this, Date2);
	 }

	 static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	 {
		 return
			 Date1.Day == Date2.Day ? (Date1.Month == Date2.Month ? (Date1.Year == Date2.Year) : false) : false;
	 }
	 bool IsDate1EqualDate2(clsDate Date2)
	 {
		 return IsDate1EqualDate2(*this, Date2);
	 }

	 static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	 {
		 return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
	 }
	 bool IsDate1AfterDate2(clsDate Date2)
	 {
		 return IsDate1AfterDate2(*this, Date2);
	 }

	 static bool IsLastDayInAMonth(clsDate Date)
	 {
		 return NumberOfDaysInAMonth(Date.Month, Date.Year) == Date.Day;
	 }
	 bool IsLastDayInAMonth()
	 {
		 return IsLastDayInAMonth(*this);
	 }

	 static bool IsLastMonthInAYear(short sMonth)
	 {
		 return sMonth == 12;
	 }
	 bool IsLastMonthInAYear()
	 {
		 return IsLastMonthInAYear(_Month);
	 }

	 static clsDate AddOneDay(clsDate Date)
	 {
		 if (IsLastDayInAMonth(Date))
		 {
			 if (IsLastMonthInAYear(Date.Month))
			 {
				 Date.Day = 1;
				 Date.Month = 1;
				 Date.Year++;
			 }
			 else
			 {
				 Date.Day = 1;
				 Date.Month++;
			 }
		 }
		 else
			 Date.Day++;

		 return Date;
	 }
	 void AddOneDay()
	 {
		 *this = AddOneDay(*this);
	 }

	 static void  SwapDates(clsDate& Date1, clsDate& Date2)
	 {

		 clsDate TempDate;
		 TempDate = Date1;
		 Date1 = Date2;
		 Date2 = TempDate;

	 }

	 static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	 {
		 int Days = 0;
		 short SawpFlagValue = 1;

		 if (!IsDate1BeforeDate2(Date1, Date2))
		 {
			 //Swap Dates 
			 SwapDates(Date1, Date2);
			 SawpFlagValue = -1;

		 }

		 while (IsDate1BeforeDate2(Date1, Date2))
		 {
			 Days++;
			 Date1 = AddOneDay(Date1);
		 }

		 return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
	 }
	 int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	 {
		 return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	 }

	 static short CalculateMyAgeInDays(clsDate DateOfBirth)
	 {
		 short TotalDays = 0;

		 return TotalDays = GetDifferenceInDays(DateOfBirth, GetSystemDate(), true);
	 }
	
	 static clsDate IncreaseDateByXDays(int Days, clsDate& Date)
	 {
		 for (int i = 1; i <= Days; i++)
		 {
			 Date = AddOneDay(Date);
		 }
		 return Date;
	 }
	 void IncreaseDateByXDays(int Days)
	 {
		 *this = IncreaseDateByXDays(Days, *this);
	 }

	 static clsDate IncreaseDateByOneWeek(clsDate& Date)
	 {
		 for (short i = 1; i <= 7; i++)
		 {
			 Date = AddOneDay(Date);
		 }
		 return Date;
	 }
	 void IncreaseDateByOneWeek()
	 {
		 *this = IncreaseDateByOneWeek(*this);
	 }

	 static clsDate IncreaseDateByXWeeks(short WeeksToAdd,clsDate& Date)
	 {
		 for (short i = 1; i <= WeeksToAdd; i++)
		 {
			 Date = IncreaseDateByOneWeek(Date);
		 }
		 return Date;
	 }
	 void IncreaseDateByXWeeks(short WeeksToAdd)
	 {
		 *this = IncreaseDateByXWeeks(WeeksToAdd, *this);
	 }

	 static clsDate IncreaseDateByOneMonth(clsDate& Date)
	 {
		 if (Date.Month == 12)
		 {
			 Date.Month = 1;
			 Date.Year++;
		 }
		 else
		 {
			 Date.Month++;
		 }

		 short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
		 if (Date.Day > NumberOfDaysInCurrentMonth)
		 {
			 Date.Day = NumberOfDaysInCurrentMonth;
		 }

		 return Date;
		
	 }
	 void IncreaseDateByOneMonth()
	 {
		 *this = IncreaseDateByOneMonth(*this);
	 }

	 static clsDate IncreaseDateByXMonths(short MonthsToAdd, clsDate& Date)
	 {
		 for (short i = 1; i <= MonthsToAdd; i++)
		 {
			 Date = IncreaseDateByOneMonth(Date);
		 }
		 return Date;
	 }
	 void IncreaseDateByXMonths(short MonthsToAdd)
	 {
		 *this = IncreaseDateByXMonths(MonthsToAdd, *this);
	 }

	 static clsDate IncreaseDateByOneYear(clsDate& Date)
	 {
		 Date.Year++;
		 return Date;
	 }
	 void IncreaseDateByOneYear()
	 {
		 *this = IncreaseDateByOneYear(*this);
	 }

	 static clsDate IncreaseDateByXYears(short YearsToAdd, clsDate& Date)
	 {
		 Date.Year += YearsToAdd;
		 return Date;
 	 }
	 void IncreaseDateByXYears(short YearsToAdd)
	 {
		 *this = IncreaseDateByXYears(YearsToAdd, *this);
	 }

	 static clsDate IncreaseDateByOneDecade(clsDate& Date)
	 {
		 Date.Year += 10;
		 return Date;
	 }
	 void IncreaseDateByOneDecade()
	 {
		 *this = IncreaseDateByOneDecade(*this);
	 }

	 static clsDate IncreaseDateByXDecades(short DecadesToAdd, clsDate& Date)
	 {
		 Date.Year += (DecadesToAdd * 10);
		 return Date;
	 }
	 void IncreaseDateByXDecades(short DecadesToAdd)
	 {
		 *this = IncreaseDateByXDecades(DecadesToAdd, *this);
	 }

	 static clsDate IncreaseDateByOneCentury(clsDate& Date)
	 {
		 Date.Year += 100;
		 return Date;
	 }
	 void IncreaseDateByOneCentury()
	 {
		 *this = IncreaseDateByOneCentury(*this);
	 }

	 static clsDate IncreaseDateByOneMillennium(clsDate& Date)
	 {
		 Date.Year += 1000;
		 return Date;
	 }
	 void IncreaseDateByOneMillennium()
	 {
		 *this = IncreaseDateByOneMillennium(*this);
	 }

	 static clsDate DecreaseDateByOneDay(clsDate& Date)
	 {
		 if (Date.Day == 1)
		 {
			 if (Date.Month == 1)
			 {
				 Date.Day = 31;
				 Date.Month = 12;
				 Date.Year--;
			 }
			 else
			 {
				 Date.Month--;
				 Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
			 }
		 }
		 else
		 {
			 Date.Day--;
		 }
		 return Date;
	 }
	 void DecreaseDateByOneDay()
	 {
		 *this = DecreaseDateByOneDay(*this);
	 }

	 static clsDate DecreaseDateByXDays(short DaysToDecrease, clsDate& Date)
	 {
		 for (short i = 1; i <= DaysToDecrease; i++)
		 {
			 Date = DecreaseDateByOneDay(Date);
		 }
		 return Date;
	 }
	 void DecreaseDateByXDays(short DaysToDecrease)
	 {
		 *this = DecreaseDateByXDays(DaysToDecrease, *this);
	 }

	 static clsDate DecreaseDateByOneWeek(clsDate& Date)
	 {
		 for (short i = 1; i <= 7; i++)
		 {
			 Date = DecreaseDateByOneDay(Date);
		 }
		 return Date;
	 }
	 void DecreaseDateByOneWeek()
	 {
		 *this = DecreaseDateByOneWeek(*this);
	 }

	 static clsDate DecreaseDateByXWeeks(short WeeksToDecrease, clsDate& Date)
	 {
		 for (short i = 1; i <= WeeksToDecrease; i++)
		 {
			 Date = DecreaseDateByOneWeek(Date);
		 }
		 return Date;
	 }
	 void DecreaseDateByXWeeks(short WeeksToDecrease)
	 {
		 *this = DecreaseDateByXWeeks(WeeksToDecrease, *this);
	 }

	 static clsDate DecreaseDateByOneMonth(clsDate& Date)
	 {
		 if (Date.Month == 1)
		 {
			 Date.Month = 12;
			 Date.Year--;
		 }
		 else
			 Date.Month--;
		
		 short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
		 if (Date.Day > NumberOfDaysInCurrentMonth)
		 {
			 Date.Day = NumberOfDaysInCurrentMonth;
		 }


		 return Date;
	 }
	 void DecreaseDateByOneMonth()
	 {
		 *this = DecreaseDateByOneMonth(*this);
	 }

	 static clsDate DecreaseDateByXMonths(short MonthsToDecrease,clsDate& Date)
	 {
		 for (short i = 1; i <= MonthsToDecrease; i++)
		 {
			 Date = DecreaseDateByOneMonth(Date);
		 }
		 return Date;
     }
	 void DecreaseDateByXMonths(short MonthsToDecrease)
	 {
		 *this = DecreaseDateByXMonths(MonthsToDecrease, *this);
	 }

	 static clsDate DecreaseDateByOneYear(clsDate& Date)
	 {
		 Date.Year--;
		 return Date;
	 }
	 void DecreaseDateByOneYear()
	 {
		 *this = DecreaseDateByOneYear(*this);
	 }

	 static clsDate DecreaseDateByXYears(short YearsToDecrease, clsDate& Date)
	 {
		 Date.Year -= YearsToDecrease;
		 return Date;
	 }
	 void DecreaseDateByXYears(short YearsToDecrease)
	 {
		 *this = DecreaseDateByXYears(YearsToDecrease, *this);
	 }

	 static clsDate DecreaseDateByOneDecade(clsDate& Date)
	 {
		 Date.Year -= 10;
		 return Date;
	 }
	 void DecreaseDateByOneDecade()
	 {
		 *this = DecreaseDateByOneDecade(*this);
	 }

	 static clsDate DecreaseDateByXDecades(short DecadesToDecrease, clsDate& Date)
	 {
		 Date.Year -= (DecadesToDecrease * 10);
		 return Date;
	 }
	 void DecreaseDateByXDecades(short DecadesToDecrease)
	 {
		 *this = DecreaseDateByXDecades(DecadesToDecrease, *this);
	 }

	 static clsDate DecreaseDateByOneCentury(clsDate& Date)
	 {
		 Date.Year -= 100;
		 return Date;
	 }
	 void DecreaseDateByOneCentury()
	 {
		 *this = DecreaseDateByOneCentury(*this);
	 }

	 static clsDate DecreaseDateByOneMillennium(clsDate& Date)
	 {
		 Date.Year -= 1000;
		 return Date;
	 }
	 void DecreaseDateByOneMillennium()
	 {
		 *this = DecreaseDateByOneMillennium(*this);
	 }

	 static bool IsEndOfWeek(clsDate Date)
	 {
		 return DayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6;
	 }
	 bool IsEndOfWeek()
	 {
		 return IsEndOfWeek(*this);
	 }

	 static bool IsWeekend(clsDate Date)
	 {
		 short DayOrder = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		 return DayOrder == 5 || DayOrder == 6;
	 }
	 bool IsWeekend()
	 {
		 return IsWeekend(*this);
	 }

	 static bool IsBusinessDay(clsDate Date)
	 {
		 return !IsWeekend(Date) && !IsEndOfWeek(Date);
	 }
	 bool IsBusinessDay()
	 {
		 return IsBusinessDay(*this);
	 }

	 static short DaysUntilEndOfWeek(clsDate Date)
	 {
		 short Days = 0;
		 short DayOrderInWeek = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		 
		 for (short i = 0; i < DayOrderInWeek; i++)
		 {
			 Days++;
		 }
		 return Days;
	 }
	 short DaysUntilEndOfWeek()
	 {
		 return DaysUntilEndOfWeek(*this);
	 }

	 static short DaysUntilEndOfMonth(clsDate Date)
	 {
		 short MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
		 short TotalDays = 0;

		 for (short i = Date.Day; i < MonthDays; i++)
		 {
			 TotalDays++;
		 }
		 return TotalDays;
	 }
	 short DaysUntilEndOfMonth()
	 {
		 return DaysUntilEndOfMonth(*this);
	 }

	 static short DaysUntilEndOfYear(clsDate Date)
	 {
		 clsDate EndOfYearDate;

		 EndOfYearDate.Day = 31;
		 EndOfYearDate.Month = 12;
		 EndOfYearDate.Year = Date.Year;

		 return GetDifferenceInDays(Date, EndOfYearDate, true);
	 }
	 short DaysUntilEndOfYear()
	 {
		 return DaysUntilEndOfYear(*this);
	 }

	 static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	 {

		 short Days = 0;
		 while (IsDate1BeforeDate2(DateFrom, DateTo))
		 {
			 if (IsBusinessDay(DateFrom))
				 Days++;

			 DateFrom = AddOneDay(DateFrom);
		 }

		 return Days;

	 }

	 static short CalculateVacationsDays(clsDate Date1, clsDate Date2)
	 {
		 short Counter = 0;

		 while (IsDate1BeforeDate2(Date1, Date2))
		 {
			 if (IsBusinessDay(Date1))
			 {
				 Counter++;
			 }
			 Date1 = AddOneDay(Date1);
		 }
		 return Counter;
	 }
	 
	 static clsDate CalculateVacationReturnDate(clsDate Date, short VacationDays)
	 {
		 clsDate ReturnDate = Date;
		 short VacationDaysCounter = 0;

		 if (IsWeekend(ReturnDate))
		 {
			 ReturnDate = AddOneDay(ReturnDate);
		 }

		 for (short i = 1; i <= VacationDays + VacationDaysCounter; i++)
		 {
			 if (IsWeekend(ReturnDate))
				 VacationDaysCounter++;

			 ReturnDate = AddOneDay(ReturnDate);
		 }

		 if (IsWeekend(ReturnDate))
		 {
			 ReturnDate = AddOneDay(ReturnDate);
		 }

		 return ReturnDate;
	 
	 }

	 enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	 static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	 {
		 if (IsDate1BeforeDate2(Date1, Date2))
			 return enDateCompare::Before;

		 if (IsDate1EqualDate2(Date1, Date2))
			 return enDateCompare::Equal;

		 
		 return enDateCompare::After;

	 }

	 enDateCompare CompareDates(clsDate Date2)
	 {
		 return CompareDates(*this, Date2);
	 }

	 static short SystemSecond()
	 {
		 time_t t = time(0);
		 tm* now = localtime(&t);

		 return now->tm_sec;
	 }
	 static short SystemMinute()
	 {
		 time_t t = time(0);
		 tm* now = localtime(&t);

		 return now->tm_min;
	 }
	 static short SystemHour()
	 {
		 time_t t = time(0);
		 tm* now = localtime(&t);

		 return now->tm_hour;
	 }



};

