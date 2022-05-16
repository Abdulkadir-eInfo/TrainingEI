#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <exception>

class DisplayAllOperation
{
	public:
	void displayall();
};

class Operations:public DisplayAllOperation
{
	public:
	int enterdetail();
	void showdetail();
	void deletedetail();	
};

#endif
