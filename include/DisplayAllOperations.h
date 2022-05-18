#ifndef DISPLAYALLOPERATIONS_H
#define DISPLAYALLOPERATIONS_H

class DisplayAllOperation
{
	public:
	void displayall();
	int count_students();
	int displayall(int); /**<  Displayall function that gives count along with all entries */
	virtual void showdetail()=0; /**< Pure Virtual Function */
};

#endif