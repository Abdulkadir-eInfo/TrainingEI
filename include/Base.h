#ifndef BASE_H
#define BASE_H
#include <vector>


class BaseOperations
{
	protected:
	int ID=100; //!< Initialization of ID,ID starts with 100.
	struct mystruct //!< Structure of all the student details
	{
		int id;
		std::string name;
		std::string branch;
		std::string location;
	}st;

	std::vector<mystruct> vect; //!< Vector to datatype mystruct that holds all the student detail
	enum
	{
		SUCCESS=0,
		FAIL=-1
	};

	public:
	BaseOperations(); //!< Constructor that transfers data from txt file into the vector
	void EnterDetail(); //!< Function is doing nothing in the parent class, will be overrided in the child class
	int CheckName(const std::string&); //!< Checks whether given Name is already present in the list
	virtual int ShowDetail(const std::string&)=0; //!< Showdetail function has no implementation here, will be implemented in dervied class
	bool VectorIsEmpty(); //!< Checks whether the Vector is Empty or Not
};

#endif