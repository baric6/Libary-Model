/*
Joe Hollon
cis 1202
july 15 2018
Baric Library
*/

#include<iostream>
#include<string>
#include <fstream>
#include "class_lib.h"
using namespace std;

int menu(int user_choice);//menu
void diplay(class_lib my_books[]);//display all books
void display_titles(fstream &data, class_lib my_books[]);//display book titles
void search(class_lib my_books[]);//search book title
void check_out(class_lib my_books[]);//subract books
void check_in(class_lib my_books[]);//add books

int main()
{
	//modify data
	class_lib my_books[6];//class object

	//now put in open file
	fstream data;//fstream object
	data.open("books.txt", ios::in);//open

	//check if open//////////////////////////////////////////////
	if (!data.fail())
	{
		cout << "--------------------" << endl;
		cout << "your file opened" << endl;
		cout << "Failed: " << data.fail() << endl;
		cout << "EOF: " << data.eof() << endl;
		cout << "Works: " << data.good() << endl;
		cout << "--------------------" << endl;
	}
	else
	{
		cout << "--------------------" << endl;
		cout << "your file failed" << endl;
		cout << "Failed: " << data.fail() << endl;
		cout << "EOF: " << data.eof() << endl;
		cout << "Works: " << data.good() << endl;
		cout << "--------------------" << endl;
	}
	///////////////////////////////////////////////////////////////////
	string name;
	string pub;
	string auth;
	string ibn;
	double price = 0;
	int year = 0;
	int stock = 0;
	////////////////////////////////////////////////////////////////////

	//reading txt for classes
	//read file first
	for (int j = 0; j < 6; j++)
	{
		//getting strings
		getline(data, name);
		getline(data, auth);
		getline(data, pub);
		getline(data, ibn);
		//getting numbers
		data >> price;
		data >> year;
		data >> stock;

		//setting to class var
		my_books[j].set_b_name(name);
		my_books[j].set_b_author(auth);
		my_books[j].set_b_publisher(pub);
		my_books[j].set_b_isbn(ibn);
		my_books[j].set_b_price(price);
		my_books[j].set_b_year(year);
		my_books[j].set_b_stock(stock);

		//reading next line
		getline(data, name);
		//////////////////////////////////////////////////////////
	}

	//for menu selection
	int user_choice = 0;//if pic
	user_choice = menu(user_choice);
	//need to make menu and if statement to choose option
	while (user_choice < 6 && user_choice > 0)
	{
		if (user_choice == 1)
		{
			cout << endl;//display all book
			cout << "Display the database" << endl;
			diplay(my_books);
			data.close();//close file
			data.clear();//used to clear flags for another read
			user_choice = menu(user_choice);
		}
		else if (user_choice == 2)
		{
			cout << endl;//display all book titles
			cout << "Displays Titles" << endl;
			display_titles(data, my_books);
			data.close();
			data.clear();
			user_choice = menu(user_choice);
		}
		else if (user_choice == 3)
		{
			cout << endl;//find book
			cout << "Search for Book" << endl;
			search(my_books);
			data.close();
			data.clear();
			user_choice = menu(user_choice);
		}
		else if (user_choice == 4)
		{
			//check out
			cout << endl;//check out
			cout << "Check Out" << endl;
			cout << "--------------------------------" << endl;
			check_out(my_books);
			data.close();
			data.clear();
			user_choice = menu(user_choice);
		}
		else if (user_choice == 5)
		{
			cout << endl;//check in
			cout << "Check In" << endl;
			cout << "--------------------------------" << endl;
			check_in(my_books);
			data.close();
			data.clear();
			user_choice = menu(user_choice);
		}
		else if (user_choice == 6)
		{
			exit(0);
		}
	}
	//system("pause");
	return 0;
}
int menu(int user_choice)//menu
{
	cout << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << "X   Baric's Library  X" << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << endl;
	cout << "press 1 Display book Inventory " << endl;
	cout << "press 2 Display book Titles " << endl;
	cout << "press 3 Search for Book " << endl;
	cout << "press 4 Book Check Out " << endl;
	cout << "press 5 Book Check In " << endl;
	cout << "press 6 To Exit " << endl;
	cout << "please pick a number: ";
	cin >> user_choice;

	return user_choice;
}
void diplay(class_lib my_books[])
{
	//data.open("books.txt", ios::in);//open
	//for loop that displays book info
	cout << "-------------------------------------" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "Book " << i +1 << ": " << endl << endl;
		cout << my_books[i].get_b_name() << endl;
		cout << my_books[i].get_b_author() << endl;
		cout << my_books[i].get_b_publisher() << endl;
		cout << my_books[i].get_b_isnb() << endl;
		cout << my_books[i].get_b_price() << endl;
		cout << my_books[i].get_b_year() << endl;
		cout << my_books[i].get_b_stock() << endl;
		cout << "----------------------------------" << endl;
	}
}
void display_titles(fstream &data, class_lib my_books[])
{
	data.open("books.txt", ios::in);//open

	cout << "--------------------------------" << endl;
	//for loop to display title of books
	for (int i = 0; i < 6; i++)
	{
		cout << my_books[i].get_b_name() << endl;
	}
}
void search(class_lib my_books[])
{
	cin.ignore();//i never know were to put this thing always a random guess
	//search by book name
	string search_word;//has to be a string for getline 
	cout << "What is the name of the book you are searching for: ";
	getline(cin, search_word);

	//linear search 
	int i = 0;
	int pos = -1;
	bool found = false;

	while(i < (6 -1) && !found)
	{
		//converted book_lib to string//**magic**//took me for ever to figure out 
		if (my_books[i].operator std::string() == search_word)
		{
			found = true;
			pos = i;
		}
		i++;
	}
	cout << endl;
	//cout << pos << endl << endl;
	
	//if to check if its a book in the library
	if (found)
	{
		cout << "We have " << my_books[pos].get_b_stock() << " copys of " << my_books[pos].get_b_name() << " left in stock " << endl;
	}
	else
	{
		cout << "We dont have the book in stock " << endl;
	}
}
void check_out(class_lib my_books[])
{
	cin.ignore();
	//search by book name
	string search_word_out;//has to be a string for getline 
	cout << "What is the name of the book you are searching for: ";
	getline(cin, search_word_out);

	int i = 0;
	int pos = -1;
	bool found = false;

	while (i < (6 - 1) && !found)
	{
		//converted book_lib to string
		if (my_books[i].operator std::string() == search_word_out)
		{
			found = true;
			pos = i;
		}
		i++;
	}

	cout << endl;

	//if to check if its a book in the library and -1 from the stock count
	if (found)
	{
		cout << my_books[pos].get_b_name() << " checked out. We have " << my_books[pos].get_b_stock() - 1 << " copys left in stock " << endl;
	}
	else
	{
		cout << "We dont have the book in stock " << endl;
	}
}
void check_in(class_lib my_books[])
{
	cin.ignore();
	//search by book name
	string search_word_in;//has to be a string for getline 
	cout << "What is the name of the book you are searching for: ";
	getline(cin, search_word_in);

	int i = 0;
	int pos = -1;
	bool found = false;

	while (i < (6 - 1) && !found)
	{
		//converted book_lib to string
		if (my_books[i].operator std::string() == search_word_in)
		{
			found = true;
			pos = i;
		}
		i++;
	}

	cout << endl;

	//if to check if its a book in the library and +1 to stock count
	if (found)
	{
		cout << my_books[pos].get_b_name() << " returned. We have " << my_books[pos].get_b_stock() + 1 << " copys left in stock " << endl;
	}
	else
	{
		cout << "We dont have the book in stock " << endl;
	}
}