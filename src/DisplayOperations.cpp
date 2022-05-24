#include <iostream>
#include <fstream>
#include <exception>
#include "DisplayOperations.h"
using namespace std;

/** Displays all the student entries */
void DisplayAllOperation::DisplayAll()
{
    int size=vect.size();
    if(0==size)
    {
        cout << "No Student Record Present" << endl;
    }
    else
    {
        cout << "\nId\tName\tBranch\tLocation" << endl;
        vector<mystruct>::iterator ptr;
        ptr=vect.begin();
        mystruct mptr;
        for (ptr = vect.begin(); ptr < vect.end(); ptr++)
        {
            mptr=*ptr;
            cout << mptr.id << "\t" << mptr.name << "\t" << mptr.branch << "\t" << mptr.location  << endl;
            
        }
    }
}

/** Displayall function that displays all entries along with count of entries */
int DisplayAllOperation::DisplayAll(int x){
    DisplayAll();
    return vect.size();
}