#pragma once
#include <iostream>
class Book
{
public:
	std::string name;
	std::string author;
	int year;
	std::string pub;
	int pages_count;
	void print_name();
	void print_fullinfo();
	Book();
	Book(std::string name, std::string author, int year, std::string pub, int pages_count);
};
