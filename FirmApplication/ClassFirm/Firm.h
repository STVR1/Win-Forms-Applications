#pragma once
#include<iostream>
#include<string>

class Firm
{

private:

	std::string projectname;
	std::string task;
	std::string executor;
	std::string supervisor;
	std::string date_of_issue;
	std::string deadline;
	std::string date_of_delivery;

public:

	Firm();

	void SetInfo(std::string* Info);

	std::string GetProjectName();

	std::string GetTask();

	std::string GetDeadLine();

	std::string GetDateOfIssue();

	std::string GetSupervisor();

	std::string GetDateOfDelivery();

	std::string GetExecutor();

	std::string GetFailExecutor();

};