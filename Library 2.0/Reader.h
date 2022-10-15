#pragma once
#include <iostream>
#include "date.h"
class Reader
{
public:
	std::string first_name;
	std::string last_name;
	date data;
	Reader(std::string first_name, std::string last_name, const date& data);
	void print_name();
	void print_fullinfo();
	bool check_reader(date current);
};

