#include "Base.h"
#ifndef OPERATIONS_H
#define OPERATIONS_H

class Operations:public BaseOperations
{
	public:
	int InputDetail(); //!< Get Input from user
	void EnterDetail(); //!< Overrided function, enters details in the .txt file
	int ShowDetail(const std::string&); //!< Virtual function implementation in the derived class that shows detail of student by matching name inputted by user
	void ShowDetail(int); //!< Shows detail of student by matching the id inputted by the user
	void DeleteDetail(); //!< Delete student entry from the file using ID
	void SaveDataToFile(); //!< Saves data from the vector to txt file
	void UpdateDetail(const std::string&); //!< Updates Student details
};

#endif