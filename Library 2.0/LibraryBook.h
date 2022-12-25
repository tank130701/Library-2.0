#pragma once
#include "Book.h"
#include "Reader.h"
#include <list>

class LibraryBook :
	public Book
{
public:
	int avilable_book_count;
	int total_count;
	std::list<Reader> list;
	int book_id;
	void add_reader(const Reader& a);
	void remove_reader(std::string name);
	void print_fullinfo();
	LibraryBook();
	LibraryBook(const Book& a, int total_count, int avilable_book_count);
};

