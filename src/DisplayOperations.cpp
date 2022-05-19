#include <iostream>
#include <cstring>
#include <fstream>
#include <exception>
#include "DisplayOperations.h"
using namespace std;

/** Displays all the student entries */
void DisplayAllOperation::displayall()
{
    string str1,str2;
    int is_studentdetail_present=0;  /**< check if there is user entry present or not */
    ifstream file_read;
    file_read.exceptions ( ifstream::badbit );
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
        if(is_studentdetail_present==0) 
        {
            cout << "\nNo Student Record Present!!!" << endl;
        }
    }
    catch(const ifstream::failure& e)
    {
        cout << "Exception opening/reading file";
    }
    file_read.close();
}

/** Displayall function that displays all entries along with count of entries */
int DisplayAllOperation::displayall(int x){
    displayall();
    int count=count_students();
    return count;
}