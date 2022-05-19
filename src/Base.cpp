#include <iostream>
#include <fstream>
#include <exception>
#include "Base.h"
using namespace std;


/**
 *  This Function is cheking for proper id format - 
 *      - has only numbers, not 0, 
 *      - removing unnecessary leading zeros, converting input id to standard form
 *      - Checking if student details with input id already exists or not
 */
string BaseOperations::check_id_before_entering(string id_input){
    string id;
    /** Checking if the user inputted id has only numbers */
    bool id_is_Number=true;
    for(char c:id_input){
        if(0==isdigit(c))
            id_is_Number=false;
    }
    
    if(false==id_is_Number){
        cout << "Student ID can only consist Numbers" << endl;
        return "-1";
    }

    /** Checking if the user inputted id is 0 */
    if("0"==id_input)
    {
        cout << "\nInvalid Input, ID must be between 1 to 999 only\n" << endl;
        return "-1";
    }

    /** Removing unnecessary leading zeros for eg. 0001, 00000001 etc. to get 1 only */
    id_input.erase(0, id_input.find_first_not_of('0'));
    
    /** Converting input id to standard form i.e. 001,011,111 */
    if(3<id_input.length() || 0==id_input.length())
    {
        cout << "\nInvalid Input, ID must be between 1 to 999 only" << endl;
        return "-1";
    }
    if(2==id_input.length())
    {
        id = "0"+id_input;
    }
    else if(1==id_input.length())
    {
        id = "00"+id_input;
    }
    else
    {
        id=id_input;
    }

    /** Checking if the student details with given id already exists!!! */
    ifstream file_read;
    file_read.exceptions ( ifstream::badbit );
    string str1,str2,check;
    int is_id_already_present=0;
    try
    {
        file_read.open("student.txt",ios::in);
    
        /** loop will run until we get line copied into the string i.e. until we reach last line */
        while ( getline(file_read,str1) )
        {   str2=str1;
            /** Get first three characters from the line(which will contain the id of the student) */
            check=str2.substr(0,3);
            /** Check if user provided id and id of the student entry is same or not */
            if(check==id)
            {
                is_id_already_present=1;
                break;
            }
        }
    }
    catch(const ifstream::failure& e)
    {
        cout << "Exception opening/reading file";
    }
    file_read.close();

    /**
    * If there exists a Student entry with the user-input id
    * ID will be unique for each student
    */
    if(1==is_id_already_present)
    {
        cout << "Student Data with given id already exists" << endl;
        return "-1";
    }
    return id;
}

/** This Function is doing nothing in this parent class */
void BaseOperations::enterdetail()
{
    cout << "Displaying Nothing in the Parent class (DisplayALlOperation), instead this function will be overrided in the Derived Class(Operations)" << endl;
}

/** Function counts the total number of student entries in the file */
int BaseOperations::count_students()
{
    string str1;
    int count=0;
    ifstream file_read;
    file_read.exceptions ( ifstream::badbit );
    try
    {
        file_read.open("student.txt",ios::in);

        /** Getting each line in a string and print it */
        while ( getline(file_read,str1) )
        {
            count++;
        }
    }
    catch(const ifstream::failure& e)
    {
        cout << "Exception opening/reading file";
        file_read.close();
        return -1;
    }
    file_read.close();
    return count;
}