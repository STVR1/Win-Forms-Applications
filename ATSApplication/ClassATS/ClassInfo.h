#pragma once

#include<iostream>

class Info
{

private:

	std::string date = "";
	int code = 0;
	std::string city = "";
	int time = 0;
	std::string rate = "";
	std::string citynumber = "";
	std::string customnumber = "";

public:

	void SetDate(std::string date);

	void SetCode(int code);

	void SetCity(std::string city);

	void SetTime(int time);

	void SetRate(std::string rate);

	void SetCitynumber(std::string citynumber);

	void SetCustomnumber(std::string customnumber);

	std::string GetDate();

	int GetCode();

	std::string GetCity();

	int GetTime();

	std::string GetRate();

	std::string GetCitynumber();

	std::string GetCustomnumber();

};