#include "LibraryBook.h"
#include "Reader.h"



void LibraryBook::add_reader(const Reader &a)
{
	this->list.push_back(a);
	avilable_book_count--;
}

void LibraryBook::remove_reader(std::string name)
{
	auto result = remove_if(list.begin(), list.end(), [name](const Reader& a)
		{
			return a.last_name == name;
		});
	list.erase(result, list.end());
	avilable_book_count++;
}



void LibraryBook::print_fullinfo()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Author: " << author << std::endl;
	std::cout << "Year of publication: " << year << std::endl;
	std::cout << "Publisher: " << pub << std::endl;
	std::cout << "Page count : " << pages_count << std::endl;
	std::cout << "Book id : " << book_id << std::endl;
	std::cout << "Total books count : " << total_count << std::endl;
	std::cout << "Avilable books count : " << avilable_book_count << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "Readers list: " << std::endl;
	for (auto iter = list.begin(); iter != list.end(); iter++)
	{
		iter->print_fullinfo();
	}
	std::cout << "===============================================" << std::endl;
}

LibraryBook::LibraryBook()
{
	std::list<Reader>;
	book_id = 0;
	total_count = 0;
	avilable_book_count = 0;
}

LibraryBook::LibraryBook(const Book& a, int total_count, int avilable_book_count)
{
	name = a.name;
	author = a.author;
	year = a.year;
	pub = a.pub;
	pages_count = a.pages_count;
	book_id = rand();
	list;
	this->total_count = total_count;
	this->avilable_book_count = avilable_book_count;
}

