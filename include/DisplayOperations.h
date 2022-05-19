#include "Operations.h"
#ifndef DISPLAYALLOPERATIONS_H
#define DISPLAYALLOPERATIONS_H

class DisplayAllOperation:public Operations
{
	public:
	void displayall(); //!< Displays all Student entries in the files
	int displayall(int); //!<  Displayall function that gives count along with all entries
};

#endif