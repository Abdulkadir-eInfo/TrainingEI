#include <iostream>
#include <cstring>
#include <fstream>
#include <exception>
#include "DisplayAllOperations.h"
using namespace std;

/*  Displays all the student entries    */
void DisplayAllOperation::displayall()
{
    string str1,str2;
    int is_user_present=0;//check if there is user entry present or not
    ifstream file_read;
    try
    {
        file_read.open("student.txt",ios::in);
        /*Getting each line in a string and print it.*/
        while ( getline(file_read,str1) )
        {
            if(is_user_present==0)
            {
                /*print the header line for the first time only*/
                cout << "\nId\tName\tBranch\tLocation" << endl;
            }
            is_user_present=1;
            str2=str1;
            cout << str1 << endl;
        }
        file_read.close();
        if(is_user_present==0) 
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
