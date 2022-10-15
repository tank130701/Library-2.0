#include "Reader.h"
#include "date.h"
#include <string>
#include <iostream>

Reader::Reader(std::string first_name, std::string last_name, const date &data)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->data = data;
}

void Reader::print_name()
{
	std::cout << "Reader last name: " << last_name << std::endl;
}

void Reader::print_fullinfo()
{
	std::cout << "Reader first name: " << first_name << std::endl;
	std::cout << "Reader last name: " << last_name << std::endl;
	data.print_date();
}

bool Reader::check_reader(date current)
{
	return data.compare(data, current);
}
