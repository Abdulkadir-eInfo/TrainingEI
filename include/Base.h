#ifndef BASE_H
#define BASE_H
#include <vector>


class BaseOperations
{
	public:
	int ID=100;
	struct mystruct //!< Structure of all the student details
	{
		int id;
		std::string name;
    	std::string branch;
    	std::string location;
	}st;

	std::vector<mystruct> vect; //!< Vector to datatype mystruct that holds all the student detail
	
	BaseOperations(); //!< Constructor that transfers data from txt file into the vector
	void EnterDetail(); //!< Function is doing nothing in the parent class, will be overrided in the child class
	int CheckName(std::string); //!< Checks whether given Name is already present in the list
	virtual int ShowDetail(std::string)=0; //!< Showdetail function has no implementation here, will be implemented in dervied class
};

#endif