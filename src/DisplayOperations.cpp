#include <iostream>
#include <fstream>
#include <exception>
#include "DisplayOperations.h"
using namespace std;

/** Displays all the student entries */
void DisplayAllOperation::DisplayAll()
{
    if(VectorIsEmpty()!=true)
    {
        cout << "\nId\tName\tBranch\tLocation" << endl;
        for (auto &ptr:vect)
        {
            if(ID<ptr.id)
                ID=ptr.id;
            cout << ptr.id << "\t" << ptr.name << "\t" << ptr.branch << "\t" << ptr.location  << endl;
            
        }
    }
    else
    {
        cout << "No Student Record Present" << endl;
    }
}

/** Displayall function that displays all entries along with count of entries */
int DisplayAllOperation::DisplayAll(int x)
{
    DisplayAll();
    return vect.size();
}

/** Destructor that transfers data from vector into the txt file to make data persistent*/
DisplayAllOperation::~DisplayAllOperation()
{
    SaveDataToFile();
}