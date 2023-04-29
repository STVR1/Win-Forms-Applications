#include"ClassInfo.h"

void Info::SetRegnum(int regnum)
{
	this->regnum = regnum;
}

void Info::SetAuthor(std::string author)
{
	this->author = author;
}

void Info::SetName(std::string name)
{
	this->name = name;
}

void Info::SetDate(int date)
{
	this->date = date;
}

void Info::SetOffice(std::string office)
{
	this->office = office;
}

void Info::SetAmount(int amount)
{
	this->amount = amount;
}

int Info::GetRegnum()
{
	return this->regnum;
}

std::string Info::GetAuthor()
{
	return this->author;
}

std::string Info::GetName()
{
	return this->name;
}

int Info::GetDate()
{
	return this->date;
}

std::string Info::GetOffice()
{
	return this->office;
}

int Info::GetAmount()
{
	return this->amount;
}