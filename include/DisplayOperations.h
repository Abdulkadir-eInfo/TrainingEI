#include "Operations.h"
#ifndef DISPLAYALLOPERATIONS_H
#define DISPLAYALLOPERATIONS_H

class DisplayAllOperation:public Operations
{
	public:
	void DisplayAll(); //!< Displays all Student entries in the files
	int DisplayAll(int); //!<  Displayall function that gives count along with all entries
	~DisplayAllOperation(); //!< Destructor that transfers data from vector into the txt file
};

#endif