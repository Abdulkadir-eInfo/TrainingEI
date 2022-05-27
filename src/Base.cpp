#include <iostream>
#include <fstream>
#include <exception>
#include "Base.h"
using namespace std;

/** Constructor that transfers data from txt file into the vector, this vector will be used for operations throughout execution */
BaseOperations::BaseOperations()
{
    string My_Id,St_Id;
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
        getline(file_read,My_Id);
        /** loop will run until we get line copied into the string i.e. until we reach last line */
        while ( getline(file_read,St_Id,'\t') )
        {
            st.id=stoi(St_Id);
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

    if(VectorIsEmpty()==true)
        ID=100;
    else
        ID=stoi(My_Id);
        
}

/** This Function is doing nothing in this parent class */
void BaseOperations::EnterDetail()
{
    cout << "Displaying Nothing in the Parent class (DisplayALlOperation), instead this function will be overrided in the Derived Class(Operations)" << endl;
}

/** Checks whether given Name is already present in the list */
int BaseOperations::CheckName(const string &checkName)
{
    for (auto &ptr:vect)
    {
        if(ptr.name==checkName)
        {
            return FAIL;
        }
    }
    return SUCCESS;
}

/** Checks whether the Vector is Empty or Not; returns true if Vector is empty */
bool BaseOperations::VectorIsEmpty()
{
    if(vect.size()==0)
        return true;
    else
        return false;
}