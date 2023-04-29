#include"Firm.h"

Firm::Firm()
{

}

void Firm::SetInfo(std::string* Info)
{
	this->projectname = Info[0];
	this->task = Info[1];
	this->executor = Info[2];
	this->supervisor = Info[3];
	this->date_of_issue = Info[4];
	this->deadline = Info[5];
	this->date_of_delivery = Info[6];
}

std::string Firm::GetProjectName()
{
	return projectname;
}

std::string Firm::GetExecutor()
{
	return executor;
}

std::string Firm::GetTask()
{
	return task;
}

std::string Firm::GetFailExecutor()
{

	std::string mainday;
	for (int i = 0; i < 2; i++)mainday += deadline[i];
	
	std::string mainmonth;
	for (int i = 3; i < 5; i++)mainmonth += deadline[i];
	
	std::string mainyear;
	for (int i = 6; i < 10; i++)mainyear += deadline[i];
	
	std::string extraday;
	for (int i = 0; i < 2; i++)extraday += date_of_delivery[i];
	
	std::string extramonth;
	for (int i = 3; i < 5; i++)extramonth += date_of_delivery[i];

	std::string extrayear;
	for (int i = 6; i < 10; i++)extrayear += date_of_delivery[i];
	
	if (stoi(extrayear) > stoi(mainyear)) return executor;
	else
	{
		if (stoi(extramonth) > stoi(mainmonth))return executor;
		else if (stoi(extramonth) == stoi(mainmonth))
		{
			if (stoi(extraday) > stoi(mainday))return executor;
		}
	}

	return "";

}

std::string Firm::GetDateOfIssue()
{
	return date_of_issue;
}

std::string Firm::GetSupervisor()
{
	return supervisor;
}

std::string Firm::GetDateOfDelivery()
{
	return date_of_delivery;
}

std::string Firm::GetDeadLine()
{
	return deadline;
}