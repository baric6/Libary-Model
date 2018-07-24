/*
Joe Hollon
cis 1202
july 15 2018
Baric Library
*/

#include<iostream>
#include<string>
#include "class_lib.h"


//set functions////////////////////////////////////////////////////////
void class_lib::set_b_name(string n)
{
	name = n;
}
void class_lib::set_b_author(string a)
{
	author = a;
}
void class_lib::set_b_publisher(string p)
{
	publisher = p;
}
void class_lib::set_b_isbn(string i)
{
	isbn = i;
}
void class_lib::set_b_price(double pr)
{
	price = pr;
}
void class_lib::set_b_year(int y)
{
	year = y;
}
void class_lib::set_b_stock(int s)
{
	stock = s;
}
//get functions/////////////////////////////////////////////////////////
string class_lib::get_b_name()
{
	return name;
}
string class_lib::get_b_author()
{
	return author;
}
string class_lib::get_b_publisher()
{
	return publisher;
}
string class_lib::get_b_isnb()
{
	return isbn;
}
double class_lib::get_b_price()
{
	return price;
}
int class_lib::get_b_year()
{
	return year;
}
int class_lib::get_b_stock()
{
	return stock;
}
///////////////////////////////////////////////////////////////////////////
class_lib::operator std::string()
{
	string temp = get_b_name();
	return temp;
}
int class_lib::get_check_out()
{
	return stock -1;
}