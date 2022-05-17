#include <iostream>
#include <cstring>
#include <fstream>
#include <exception>
#include "Operations.h"
using namespace std;

/** Enter student details in the file */
int Operations::enterdetail()
{
    string id_input,id;
	char name[20],location[15],branch[10];
	cout << "\nEnter the student details:" << endl;
	cout << "ID(1 to 999):";
	cin >> id_input;
    if(id_input=="0")
    {
        cout << "\nInvalid Input, ID must be between 1 to 999 only\n" << endl;
        return 0;
    }

    /** Removing unnecessary leading zeros for eg. 0001, 00000001 etc. to get 1 only */
    id_input.erase(0, id_input.find_first_not_of('0'));
    
    /** Converting input id to standard form i.e. 001,011,111 */
    if(id_input.length()>3 || id_input.length()==0)
    {
        cout << "\nInvalid Input, ID must be between 001 to 999 only" << endl;
        return 0;
    }
    if(id_input.length()==2)
    {
        id = "0"+id_input;
    }
    else if(id_input.length()==1)
    {
        id = "00"+id_input;
    }
    else
    {
        id=id_input;
    }

    /** Checking if the student details with given id already exists!!! */
    ifstream file_read;
    string str1,str2,check;
    int is_id_already_present=0;

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
    file_read.close();

    /**
    * If there exists a Student entry with the user-input id
    * ID will be unique for each student
    */
    if(is_id_already_present==1)
    {
        cout << "Student Data with given id already exists" << endl;
        return -1;
    }

    cout << "Name:";
    cin >> name;
    cout << "Branch:";
    cin >> branch;
    cout << "Location:";
    cin >> location;
    ofstream file_write;

    /** Exception Handling to handle file exceptions */
    try
    {
        file_write.open("student.txt",ios::app);
        file_write << id << "\t" << name << "\t" << branch << "\t" << location << endl;

        /**
        * Checking for good bit
        * The good( ) function returns a non-zero (true) value when no error has occurred; otherwise returns zero (false).
        */
        if(file_write.good())
            cout << "Student Data Inserted Successfully" << endl;
        file_write.close();
    }
    catch(exception& e)
    {
        cout << "Exception caught" << endl;
        file_write.close();
    }
    return 0;
}

/** Show student details for given ID, reading from file */
void Operations::showdetail()
{
    int is_user_present=0;
    string to_check,input_id;
    string str1,str2,check;
    cout << "\nEnter the id of the student you want to show data: ";
    cin >> input_id;
    /** Converting input id to standard form i.e. 001,011,111 for proper checking with stduent entries present */
    if(input_id.length()==2)
    {
        to_check = "0"+input_id;
    }
    else if(input_id.length()==1)
    {
        to_check = "00"+input_id;
    }
    else
    {
        to_check=input_id;
    }
    ifstream file_read;

    /** Exception Handling to handle file exceptions */
    try
    {
        file_read.open("student.txt",ios::in);
        while ( getline(file_read,str1) )
        {   
            str2=str1;
            check=str2.substr(0,3);
            if(check==to_check)
            {
                is_user_present=1;
                cout << "\nId\tName\tBranch\tLocation" << endl;
                cout << str1 << endl;
            }
        }
        file_read.close();

        if(is_user_present==0)
            cout << "Student record not found!!!" << endl;

    }
    catch(exception& e)
    {
        cout << "Exception caught" << endl;
        file_read.close();
    }
}

/** Delete student details with given ID */
void Operations::deletedetail()
{
    int is_student_present=0;
    string str1,str2,deleted_string,to_check,check,input_id;
    cout << "\nEnter the id of the student you want to delete: ";
    cin >> input_id;
    if(input_id.length()==2)
    {
        to_check = "0"+input_id;
    }
    else if(input_id.length()==1)
    {
        to_check = "00"+input_id;
    }
    else
    {
        to_check=input_id;
    }

    fstream file_readwrite;    /**< For student.txt file */
    fstream file_readwrite_bkp;     /**< For studentbckp.txt file */
    /** Exception Handling to handle file exceptions */
    try
    {
        file_readwrite.open("student.txt",ios::in);
        file_readwrite_bkp.open("studentbckp.txt",ios::out);
        while ( getline(file_readwrite,str1) )
        {   
            str2=str1;
            check=str2.substr(0,3);
            /** If the id is same as the id provided by user, the entry of that student in studentbckp.txt will be skipped */
            if(check==to_check)
            {
                is_student_present=1;
                deleted_string=str2;
                continue;
            }
            file_readwrite_bkp << str2 << "\n";
        }
        file_readwrite.close();
        file_readwrite_bkp.close();

        /** Copying data from backup to back into the original file */
        file_readwrite_bkp.open("studentbckp.txt",ios::in);
        file_readwrite.open("student.txt",ios::out);
        while ( getline(file_readwrite_bkp,str1) )
        {   
            str2=str1;
            file_readwrite << str2 << "\n";
        }
        file_readwrite_bkp.close();
        file_readwrite.close();

        if(is_student_present==0)
            cout << "Student record not found!!!" << endl;
        else if(is_student_present==1)
            cout << "\nFollowing record of Student deleted successfully:\n" << deleted_string << endl; 

    }
    catch(exception& e)
    {
        cout << "Exception caught" << endl; 
        file_readwrite.close();
        file_readwrite_bkp.close();
    }

}