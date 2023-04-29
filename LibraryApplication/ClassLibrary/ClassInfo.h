#pragma once
#include<iostream>

class Info
{

private:

	int regnum = 0;
	std::string author="";
	std::string name = "";
	int date = 0;
	std::string office = "";
	int amount = 0;

public:

	void SetRegnum(int regnum);

	void SetAuthor(std::string author);

	void SetName(std::string name);

	void SetDate(int date);

	void SetOffice(std::string office);

	void SetAmount(int amount);

	int GetRegnum();

	std::string GetAuthor();

	std::string GetName();
	
	int GetDate();

	std::string GetOffice();

	int GetAmount();

};