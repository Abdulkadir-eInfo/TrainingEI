#include <iostream>
#include <cstring>
#include <fstream>
#include <exception>
#include "DisplayAllOperations.h"
using namespace std;

/** Displays all the student entries */
void DisplayAllOperation::displayall()
{
    string str1,str2;
    int is_studentdetail_present=0;  /**< check if there is user entry present or not */
    ifstream file_read;
    try
    {
        file_read.open("student.txt",ios::in);

        /** Getting each line in a string and print it */
        while ( getline(file_read,str1) )
        {
            if(is_studentdetail_present==0)
            {
                /** print the header line for the first time only */
                cout << "\nId\tName\tBranch\tLocation" << endl;
            }
            is_studentdetail_present=1;
            str2=str1;
            cout << str1 << endl;
        }
        file_read.close();
        if(is_studentdetail_present==0) 
        {
            cout << "\nNo Student Record Present!!!" << endl;
        }
    }
    catch(exception& e)
    {
        cout << "Exception caught" << endl;
        file_read.close();
    }
}

/** This Function is doing nothing in the parent class */
void DisplayAllOperation::enterdetail()
{
    cout << "Displaying Nothing in the Parent class (DisplayALlOperation), instead this function will be overrided in the Derived Class(Operations)" << endl;
}

/** Function counts the total number of student entries in the file */
int DisplayAllOperation::count_students()
{
    string str1;
    int count=0;
    ifstream file_read;
    try
    {
        file_read.open("student.txt",ios::in);

        /** Getting each line in a string and print it */
        while ( getline(file_read,str1) )
        {
            count++;
        }
        file_read.close();
    }
    catch(exception& e)
    {
        cout << "Exception caught" << endl;
        file_read.close();
    }
    return count;
}

/** Displayall function that displays all entries along with count of entries */
int DisplayAllOperation::displayall(int x){
    displayall();
    int count=count_students();
    return count;
}