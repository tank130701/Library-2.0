// Library 2.0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>
#include "Book.h"
#include "LibraryBook.h"
#include <string>
#include "Reader.h"

class Library
{
    std::list<Book> list;
    std::list<LibraryBook> list1;
public:
	void create_new_book();
	void remove_book();
	void add_book_to_library();
	void print_books();
	void print_library_books();
	void find_book_by_name();
};

int menu() {
	std::cout << "\n1. Create Book\n"
		"2. Delete Book\n"
		"3. Append book to catalog\n"
		"4. Remove book from catalog\n"
		"5. Print info about book by id\n"
		"6. Print Books list\n"
		"7. Print Library Books list\n"
		"8. Add reader to Library book\n"
		"9. Remove reader from library book\n"
		"10. Search by Book id\n"
		"11. Search by Book name\n"
		"12. Search by Book author\n"
		"0. Exit " << std::endl;
	int cmd;
	std::cout << "~$ ";
	std::cin >> cmd;
	return cmd;
};

void Library::create_new_book()
{
	int year, count;
	std::string author, pub, name;
	std::cout << "Enter name of book: ";
	std::getline(std::cin, name);
	std::getline(std::cin, name);
	std::cout << "Enter author of book: ";
	std::getline(std::cin, author);
	std::cout << "Enter year of publication: ";
	std::cin >> year;
	std::cout << "Enter publisher: ";
	std::cin >> pub;
	std::cout << "Enter count of pages: ";
	std::cin >> count;
	Book* a = new Book(name, author, year, pub, count);
	list.push_back(*a);
}

void Library::remove_book()
{
	for (auto iter = list.begin(); iter != list.end(); iter++)
	{
		iter->print_name();
	}
	std::string name;
	std::cout << "Enter the title of book which you want to delete: ";
	std::cin >> name;
	/*for (auto iter = list.begin(); iter != list.end(); iter++)
	{
		if (iter->name == name)
		{
			auto iter_d = iter;
			list.erase(iter_d);
		}
	}*/
	
}

void Library::add_book_to_library()
{
	int total_count;
	for (auto iter = list.begin(); iter != list.end(); iter++)
	{
		iter->print_name();
		std::cout << "Enter count of Books: ";
		std::cin >> total_count;
		LibraryBook* b = new LibraryBook(*iter, total_count, total_count);
		list1.push_back(*b);
	}

}

void Library::print_books()
{
	for (auto iter = list.begin(); iter != list.end(); iter++)
	{
		iter->print_fullinfo();
	}
}

void Library::find_book_by_name()
{
	std::string name;
	std::cout << "Enter the name of book: ";
	std::cin >> name;
	for (auto iter = list.begin(); iter != list.end(); iter++)
	{
		if (iter->name == name)
			iter->print_fullinfo();
		else
			std::cout << "Book with this name not found.\n";
	}
		
}


void Library::print_library_books()
{
	for (auto iter = list1.begin(); iter != list1.end(); iter++)
	{
		iter->print_fullinfo();
	}
}


int main()
{
	Library Library;
	while (true)
	{
		int cmd = menu();
		bool exit = false;
		switch (cmd) {
		case 0:
			exit = true;
			break;
		case 1:
			Library.create_new_book();
			break;
		case 2:
			Library.remove_book();
			break;
		case 3:
			Library.add_book_to_library();
			break;
		case 4:
			break;
		case 5:
			//list.print();
			break;
		case 6:
			Library.print_books();
			break;
		case 7:
			Library.print_library_books();
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			Library.find_book_by_name();
			break;
		case 12:
			break;
		};
		if (exit == true) break;
	};
}



