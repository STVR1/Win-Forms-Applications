#include"Date.h"

void Date::Set(std::string date) 
{
	this->date = date;

	for (int i = 0; i < 2; i++)day.push_back(date[i]);
	
	for (int i = 3; i < 5; i++)month.push_back(date[i]);

	for (int i = 6; i < 10; i++)year.push_back(date[i]);

	
}

Date::Date()
{

}

bool Date::IsLeap() 
{

	if (stoi(year) % 4 == 0)return true;
	else return false;

}

short Date::WeekNumber()
{
	int extradays = (365 * stoi(year) - 365 + stoi(year) / 4)%7;
	short amountdays = 0;
	for (int i = 1; i <= stoi(month); i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
		{
			if (i == stoi(month))amountdays += stoi(day);
			else amountdays += 31;
		}
		else if (i == 2)
		{
			if (stoi(year) % 4 == 0)
			{
				if (i == stoi(month))amountdays += stoi(day);
				else amountdays += 29;
			}
			else
			{
				if (i == stoi(month))amountdays += stoi(day);
				else amountdays += 28;
			}
		}
		else
		{
			if (i == stoi(month))amountdays += stoi(day);
			else amountdays += 30;
		}
	}
	
	if (extradays == 1)
	{
		if (amountdays % 7 == 0)return amountdays / 7 + 1;
		else return amountdays / 7;
	}
	else
	{
		switch (extradays)
		{
		case 0:
		{
			amountdays -= 1;
			break;
		}
		case 2:
		{
			amountdays -= 6;
			break;
		}
		case 3:
		{
			amountdays -= 5;
			break;
		}
		case 4:
		{
			amountdays -= 4;
			break;
		}
		case 5:
		{
			amountdays -= 3;
			break;
		}
		case 6:
		{
			amountdays -= 2;
			break;
		}
		}
		if (amountdays <= 0)return 52;
		if (amountdays % 7 == 0)return amountdays / 7;
		else return amountdays / 7 + 1;
	}
}

std::string Date::NextDay()
{
	if (day == "28" && month == "02")
	{
		if (stoi(year) % 4 == 0)return "29.02." + year;
		else return"01.03." + year;
	}
	else if (day == "29" && month == "02")return "01.03." + year;
	else if (day == "30")
	{
		if (month == "04")return"01.05."+year;
		else if (month == "06")return "01.07." + year;
		else if (month == "09")return "01.10." + year;
		else if (month == "11")return "01.12." + year;
		else return "31." + month+"." + year;
	}
	else if (day == "31")
	{
		if (month == "12")
		{
			std::string newyear= std::to_string(stoi(year) + 1);
			if (stoi(newyear) >= 0 && stoi(newyear) < 10)return  "01.01.000" + newyear;
			else if (stoi(newyear) >= 10 && stoi(newyear) < 100)return "01.01.00" + newyear;
			else if (stoi(newyear) >= 100 && stoi(newyear) < 1000)return "01.01.0" + newyear;
			else return "01.01." + newyear;
		}
		else
		{
			std::string newmonth = std::to_string(stoi(month) + 1);
			if (stoi(newmonth) < 10)return "01.0" + newmonth + "." + year;
			else return "01." + newmonth + "." + year;
		}
	}
	else
	{
		int newday = stoi(day)+1;
		if(newday<10)return "0"+std::to_string(newday) + "." + month + "." + year;
		else return std::to_string(newday) + "." + month + "." + year;
	}
	
}

std::string Date::PreviousDay()
{

	if (day == "01")
	{
		if (month == "01")
		{
			int newyear = stoi(year) - 1;
			if(newyear<10)return "31.12.000"+ std::to_string(stoi(year) - 1);
			else if(newyear>=10 && newyear<100)return "31.12.00" + std::to_string(stoi(year) - 1);
			else if(newyear>=100 && newyear<1000)return "31.12.0" + std::to_string(stoi(year) - 1);
			else return "31.12." + std::to_string(stoi(year) - 1);
		}
		else if (month == "02" || month == "04" || month == "06" || month == "09" || month == "11")
		{
			int newmonth = stoi(month)-1;
			if(newmonth<10)return "31.0"+ std::to_string(stoi(month) - 1) + "." + year;
			else return "31." + std::to_string(stoi(month) - 1) + "." + year;
		}
		else if (month == "05" || month == "07" || month == "10" || month == "12")
		{
			int newmonth = stoi(month) - 1;
			if (newmonth < 10)return "30.0" + std::to_string(stoi(month) - 1) + "." + year;
			else return "30." + std::to_string(stoi(month) - 1) + "." + year;
		}
		else if (month == "03")
		{
			if (stoi(year) % 4 == 0)return "29.02." + year;
			else return "28.02." + year;
		}
		else return "31.07." + year;
	}
	else
	{
		int newday = stoi(day) - 1;
		if (newday < 10)return "0"+std::to_string(stoi(day) - 1) + "." + month + "." + year;
		else return std::to_string(stoi(day) - 1) + "." + month + "." + year;
	}

}

int Date::DaysTillYourBirthday(Date birthdaydate)
{
	int difference = 0;

	if (stoi(birthdaydate.month) > stoi(month))
	{
		for(int i=stoi(month);i<=stoi(birthdaydate.month);i++)
		{
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			{
				if (i == stoi(month)) difference +=31- stoi(day);
				else if (i == stoi(birthdaydate.month))difference += stoi(birthdaydate.day);
				else difference += 31;
			}
			else if (i == 2)
			{
				if (stoi(year) % 4 == 0)
				{
					if (i == stoi(month)) difference += 29-stoi(day);
					else if (i == stoi(birthdaydate.month))difference += stoi(birthdaydate.day);
					else difference += 29;
				}
				else
				{
					if (i == stoi(month)) difference +=28-stoi(day);
					else if (i == stoi(birthdaydate.month))difference += stoi(birthdaydate.day);
					else difference += 28;
				}
			}
			else
			{
				if (i == stoi(month)) difference += 30-stoi(day);
				else if (i == stoi(birthdaydate.month))difference += stoi(birthdaydate.day);
				else difference += 30;
			}
		}
	}
	else if (stoi(birthdaydate.month) == stoi(month))
	{
		difference = stoi(birthdaydate.day) - stoi(day);
		if (difference <= 0)
		{
			if ((stoi(year) + 1) % 4 == 0)return 366 + difference;
			else return 365 + difference;
		}
		else return difference;
	}
	else
	{
		for (int i = stoi(month); i <= 12; i++)
		{
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			{
				if (i == stoi(month)) difference += stoi(day);
				else if (i == stoi(birthdaydate.month))difference += stoi(birthdaydate.day);
				else difference += 31;
			}
			else if (i == 2)
			{
				if (stoi(year) % 4 == 0)
				{
					if (i == stoi(month)) difference += stoi(day);
					else if (i == stoi(birthdaydate.month))difference += stoi(birthdaydate.day);
					else difference += 29;
				}
				else
				{
					if (i == stoi(month)) difference += stoi(day);
					else if (i == stoi(birthdaydate.month))difference += stoi(birthdaydate.day);
					else difference += 28;
				}
			}
			else
			{
				if (i == stoi(month)) difference += stoi(day);
				else if (i == stoi(birthdaydate.month))difference += stoi(birthdaydate.day);
				else difference += 30;
			}
		}

		for (int i = 1; i <= stoi(birthdaydate.month); i++)
		{
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			{
				if (i == stoi(month)) difference += stoi(day);
				else if (i == stoi(birthdaydate.month))difference += stoi(birthdaydate.day);
				else difference += 31;
			}
			else if (i == 2)
			{
				if ((stoi(year)+1) % 4 == 0)
				{
					if (i == stoi(month)) difference += stoi(day);
					else if (i == stoi(birthdaydate.month))difference += stoi(birthdaydate.day);
					else difference += 29;
				}
				else
				{
					if (i == stoi(month)) difference += stoi(day);
					else if (i == stoi(birthdaydate.month))difference += stoi(birthdaydate.day);
					else difference += 28;
				}
			}
			else
			{
				if (i == stoi(month)) difference += stoi(day);
				else if (i == stoi(birthdaydate.month))difference += stoi(birthdaydate.day);
				else difference += 30;
			}
		}

	}
	if (difference == 0)if ((stoi(year) + 1) % 4 == 0)difference = 366; else difference = 365;
	return difference;
}

int Date::Duration(Date date)
{
	int counterentereddate = 365*stoi(date.year)-365+ (stoi(date.year) - 1) / 4,
		countercurrentdate = 365*stoi(year)-365+ (stoi(year) - 1) / 4;

	for (int i = 1; i <= stoi(date.month); i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
		{
			if (i == stoi(date.month))counterentereddate += stoi(date.day);
			else counterentereddate += 31;
		}
		else if (i == 2)
		{
			if (stoi(date.year) % 4 == 0)
			{
				if (i == stoi(date.month))counterentereddate += stoi(date.day);
				else counterentereddate += 29;
			}
			else
			{
				if (i == stoi(date.month))counterentereddate += stoi(date.day);
				else counterentereddate += 28;
			}
		}
		else
		{
			if (i == stoi(date.month))counterentereddate += stoi(date.day);
			else counterentereddate += 30;
		}
	}

	for (int i = 1; i <= stoi(month); i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
		{
			if (i == stoi(month))countercurrentdate += stoi(day);
			else countercurrentdate += 31;
		}
		else if (i == 2)
		{
			if (stoi(year) % 4 == 0)
			{
				if (i == stoi(month))countercurrentdate += stoi(day);
				else countercurrentdate += 29;
			}
			else
			{
				if (i == stoi(month))countercurrentdate += stoi(day);
				else countercurrentdate += 28;
			}
		}
		else
		{
			if (i == stoi(month))countercurrentdate += stoi(day);
			else countercurrentdate += 30;
		}
	}

	return  abs(countercurrentdate - counterentereddate);

}