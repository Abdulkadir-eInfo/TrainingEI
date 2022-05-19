#include "Base.h"
#ifndef OPERATIONS_H
#define OPERATIONS_H

class Operations:public BaseClass
{
	public:
	int enterdetail(); //!< Overrided function, enters details in the .txt file
	void showdetail(); //!< Virtual function implementation in the derived class
	void deletedetail(); //!< Delete student entry from the file using ID
};

#endif