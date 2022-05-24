#include <iostream>
#include <fstream>
#include <exception>
#include "Base.h"
using namespace std;

/** Constructor that transfers data from txt file into the vector, this vector will be used for operations throughout execution */
BaseOperations::BaseOperations()
{
    string line,word;
    ifstream file_read;
    
    try
    {
        file_read.open("student.txt",ios::in);
        if(!file_read)
        {
            ofstream file_write;
            file_write.open("student.txt",ios::out);
            file_write.close();
        }

        /** loop will run until we get line copied into the string i.e. until we reach last line */
        while ( getline(file_read,st.id,'\t') )
        {
            getline(file_read,st.name,'\t');
            getline(file_read,st.branch,'\t');
            getline(file_read,st.location,'\t');
            vect.push_back(st);
        }
    }
    catch(const ifstream::failure& e)
    {
        cout << "Exception opening/reading file";
    }
    file_read.close();

}



/** This Function is doing nothing in this parent class */
void BaseOperations::EnterDetail()
{
    cout << "Displaying Nothing in the Parent class (DisplayALlOperation), instead this function will be overrided in the Derived Class(Operations)" << endl;
}

/** Checks whether given Name is already present in the list */
int BaseOperations::CheckName(string checkName)
{
    vector<mystruct>::iterator ptr;
    ptr=vect.begin();
    mystruct find_ptr;
    for (ptr = vect.begin(); ptr < vect.end(); ptr++)
    {
        mystruct mptr=*ptr;
        if(mptr.name==checkName){
            return -1;
        }
    }
    return 0;
}


/** Saves data from the vector to txt file */
void BaseOperations::SaveDataToFile()
{
    int size=vect.size();
    if(0!=size)
    {
        ofstream file_write;
        try
        {
            file_write.open("student.txt",ios::out);
            vector<mystruct>::iterator ptr;
            ptr=vect.begin();
            mystruct find_ptr;
            for (ptr = vect.begin(); ptr < vect.end(); ptr++)
            {
                mystruct mptr=*ptr;
                file_write << mptr.id << "\t" << mptr.name << "\t" << mptr.branch << "\t" << mptr.location << "\t";
            }
            
        }
        catch(const ofstream::failure& e)
        {
            cout << "Exception opening/reading file";
        }
        file_write.close();
    }
}

/** Destructor that transfers data from vector into the txt file to make data persistent*/
BaseOperations::~BaseOperations() 
{
    SaveDataToFile();
}