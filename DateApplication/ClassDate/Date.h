#pragma once
#include<iostream>
#include<cmath>
#include<string>

class Date
{
	
private:

	std::string date=""; // entered date

	std::string day=""; // entered day

	std::string month=""; // entered month

	std::string year=""; // entered year

public:

	// divide entered date into separate parts (day, month, year)

	Date();

	void Set(std::string date);

	// returns the date of tomorrow

	std::string NextDay();

	// returns the date of yesterday

	std::string PreviousDay();

	// checks, if this year is leap

	bool IsLeap();

	// 

	short WeekNumber();

	// returns the amount of days till the birhday date

	int DaysTillYourBirthday(Date birthdaydate);

	// returns the amount of days between the current date and the entered date

	int Duration(Date date);

};