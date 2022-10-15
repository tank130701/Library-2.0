// Library 2.0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>
#include "Book.h"
#include "LibraryBook.h"
#include <string>
#include "Reader.h"
#include <sstream>

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
	void remove_book_from_library();
	void find_book_by_id();
	void find_books_by_author();
	void add_reader();
	void remove_reader();
	void check_readers();
};

int menu() {
	std::cout << "\n1. Create Book\n"
		"2. Delete Book\n"
		"3. Append book to catalog\n"
		"4. Remove book from catalog\n"
		"5. Print Books list\n"
		"6. Print Library Books list\n"
		"7. Add reader to Library book\n"
		"8. Remove reader from library book\n"
		"9. Search by Book id\n"
		"10. Search by Book name\n"
		"11. Search by Book author\n"
		"12. Check readers\n"
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
	auto result = remove_if(list.begin(), list.end(), [name](const Book& a)
		{
			return a.name == name;
		});
	list.erase(result, list.end());
	
}

void Library::remove_book_from_library()
{
	for (auto iter = list1.begin(); iter != list1.end(); iter++)
	{
		iter->print_name();
	}
	std::string name;
	std::cout << "Enter the title of book which you want to delete: ";
	std::cin >> name;
	auto result = remove_if(list1.begin(), list1.end(), [name](const LibraryBook& a)
		{
			return a.name == name;
		});
	list1.erase(result, list1.end());

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
	for (auto iter = list1.begin(); iter != list1.end(); iter++)
	{
		if (iter->name == name)
			iter->print_fullinfo();
		else
			std::cout << "Book with this name not found.\n";
	}
		
}

void Library::find_book_by_id()
{
	int id;
	std::cout << "Enter the id of book: ";
	std::cin >> id;
	for (auto iter = list1.begin(); iter != list1.end(); iter++)
	{
		if (iter->book_id == id)
			iter->print_fullinfo();
		else
			std::cout << "Book with this id not found.\n";
	}

}

void Library::find_books_by_author()
{
	std::string author;
	std::cout << "Enter the author of book: ";
	std::cin >> author;
	std::list<LibraryBook> check;
	for (auto iter = list1.begin(); iter != list1.end(); iter++)
	{
		if (iter->author == author)
			check.push_back(*iter);
		else
			std::cout << "Books from this author not found.\n";
	}
	for (auto iter = check.begin(); iter != check.end(); iter++)
	{
		iter->print_fullinfo();
	}
}

void Library::add_reader()
{
	for (auto iter = list1.begin(); iter != list1.end(); iter++)
	{
		iter->print_name();
	}
	std::string name;
	std::cout << "Enter the name of book: ";
	std::cin >> name;
	std::string firstname, lastname;
	std::cout << "Enter Reader's first name: ";
	std::cin >> firstname;
	std::cout << "Enter Reader's last name: ";
	std::cin >> lastname;
	Reader* newreader;
	std::string str;
	std::cout << "Enter current date: ";
	std::getline(std::cin, str);
	std::getline(std::cin, str);
	std::stringstream ss;
	int dd, mm, yy;
	ss << str;
	ss >> dd;
	ss.seekg(3);
	ss >> mm;
	ss.seekg(6);
	ss >> yy;
	date data = date(dd, mm, yy);
	newreader = new Reader(firstname, lastname, data);
	
	for (auto iter = list1.begin(); iter != list1.end(); iter++)
	{
		if (iter->name == name)
			iter->add_reader(*newreader);
		else
			std::cout << "Book with this name not found.\n";
	}

}

void Library::remove_reader()
{
	std::string lastname;
	std::cout << "Enter Reader's last name of reader which you want to remove: ";
	std::cin >> lastname;
	std::string name;
	std::cout << "Enter the name of book where you want to delete reader: ";
	std::cin >> name;
	for (auto iter = list1.begin(); iter != list1.end(); iter++)
	{
		iter->print_name();
	}
	for (auto iter = list1.begin(); iter != list1.end(); iter++)
	{
		if (iter->name == name)
			iter->remove_reader(lastname);
		else
			std::cout << "Book with this name not found.\n";
	}

}

void Library::check_readers()
{
	std::string str;
	std::cout << "Enter current date: ";
	std::getline(std::cin, str);
	std::getline(std::cin, str);
	std::stringstream ss;
	int dd, mm, yy;
	ss << str;
	ss >> dd;
	ss.seekg(3);
	ss >> mm;
	ss.seekg(6);
	ss >> yy;
	date data = date(dd, mm, yy);
	std::list<Reader> check;
	for (auto iter = list1.begin(); iter != list1.end(); iter++)
	{	
		for (auto iter1 = iter->list.begin(); iter1 != iter->list.end(); iter1++)
			if (iter1->check_reader(data))
				check.push_back(*iter1);
			
	}
	for (auto iter = check.begin(); iter != check.end(); iter++)
	{
		iter->print_fullinfo();
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
			Library.remove_book_from_library();
			break;
		case 5:
			Library.print_books();
			break;
		case 6:
			Library.print_library_books();
			break;
		case 7:
			Library.add_reader();
			break;
		case 8:
			Library.remove_reader();
			break;
		case 9:
			Library.find_book_by_id();
			break;
		case 10:
			Library.find_book_by_name();
			break;
		case 11:
			Library.find_books_by_author();
			break;
		case 12:
			Library.check_readers();
			break;
		};
		if (exit == true) break;
	};
}



