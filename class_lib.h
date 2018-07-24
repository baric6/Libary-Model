#pragma once
/*
Baric
cis 1202
july 15 2018
Baric Library
*/

#ifndef class_lib_H
#define class_lib_H
#include<iostream>
#include<string>

using namespace std;

class class_lib
{
private:
	//define member varables//////////////////////////////
	string name;
	string author;
	string publisher;
	string isbn;
	double price;
	int year;
	int stock;
public:
	//define member functions
	//set functions///////////////////////////////////////
	void set_b_name(string);
	void set_b_author(string);
	void set_b_publisher(string);
	void set_b_isbn(string);
	void set_b_price(double);
	void set_b_year(int);
	void set_b_stock(int);
	//get functions///////////////////////////////////////
	string get_b_name();
	string get_b_author();
	string get_b_publisher();
	string get_b_isnb();
	double get_b_price();
	int get_b_year();
	int get_b_stock();
	operator std::string();
	//////////////////////////////////////////////////////
	int get_check_out();
};
#endif
