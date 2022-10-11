#pragma once
#include <iostream>

class Reader
{
public:
	std::string first_name;
	std::string last_name;
	Reader(std::string first_name, std::string last_name);
	void print_name();
	void print_fullinfo();

};

