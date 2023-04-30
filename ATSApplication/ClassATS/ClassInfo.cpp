#include"ClassInfo.h"

void Info::SetCity(std::string city)
{
	this->city = city;
}

void Info::SetCitynumber(std::string citynumber)
{
	this->citynumber = citynumber;
}

void Info::SetCode(int code)
{
	this->code = code;
}

void Info::SetCustomnumber(std::string customnumber)
{
	this->customnumber = customnumber;
}

void Info::SetDate(std::string date)
{
	this->date = date;
}

void Info::SetRate(std::string rate)
{
	this->rate = rate;
}

void Info::SetTime(int time)
{
	this->time = time;
}

std::string Info::GetCity()
{
	return this->city;
}

std::string Info::GetCitynumber()
{
	return this->citynumber;
}

int Info::GetCode()
{
	return this->code;
}

std::string Info::GetCustomnumber()
{
	return this->customnumber;
}

std::string Info::GetDate()
{
	return this->date;
}

std::string Info::GetRate()
{
	return this->rate;
}

int Info::GetTime()
{
	return this->time;
}