#ifndef BASE_H
#define BASE_H
#include <vector>

static int ID=100;
class BaseOperations
{
	public:
	struct mystruct //!< Structure of all the student details
	{
		std::string id;
		std::string name;
    	std::string branch;
    	std::string location;
	}st;

	std::vector<mystruct> vect;
	
	BaseOperations(); //!< Constructor that transfers data from txt file into the vector
	void EnterDetail(); //!< Function is doing nothing in the parent class, will be overrided in the child class
	int CheckName(std::string); //!< Checks whether given Name is already present in the list
	void SaveDataToFile(); //!< Saves data from the vector to txt file
	int GetId();
	void SetId(int);
	virtual void ShowDetail()=0; //!< Showdetail function has no implementation here, will be implemented in dervied class
	~BaseOperations(); //!< Destructor that transfers data from vector into the txt file
};

#endif