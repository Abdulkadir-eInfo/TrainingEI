#include "DisplayAllOperations.h"
#ifndef OPERATIONS_H
#define OPERATIONS_H

class Operations:public DisplayAllOperation
{
	public:
	int enterdetail();
	void showdetail();
	void deletedetail();	
};

#endif