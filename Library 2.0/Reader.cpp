#include "Reader.h"
#include <string>
#include <iostream>

Reader::Reader(std::string first_name, std::string last_name)
{
	this->first_name = first_name;
	this->last_name = last_name;

}

void Reader::print_name()
{
	std::cout << "Reader last name: " << last_name << std::endl;
}

void Reader::print_fullinfo()
{
	std::cout << "Reader first name: " << first_name << std::endl;
	std::cout << "Reader last name: " << last_name << std::endl;
	//std::cout << "Date of issue: " << std::ctime(&end_time) << std::endl;
}
