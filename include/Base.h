#ifndef BASE_H
#define BASE_H

class BaseClass
{
	public:
    std::string check_id_before_entering(std::string); //!< ID checking for proper format
	void enterdetail(); //!< Function is doing nothing in the parent class, will be overrided in the child class
	int count_students(); //!< Counts student entries in the file
	virtual void showdetail()=0; //!< Pure Virtual Function
};

#endif