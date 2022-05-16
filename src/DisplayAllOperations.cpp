#include "DisplayAllOperations.h"
using namespace std;

//Displays all the student entries
void DisplayAllOperation::displayall()
{
    string s,c;
    int flag=0;//check if there is user entry present or not
    fstream fi;
    try
    {
        fi.open("student.txt",ios::in);
        //Getting each line in a string and print it.
        while ( getline(fi,s) )
        {
            if(flag==0)
            {
                //print the header line for the first time only
                cout << "\nId\tName\tBranch\tLocation" << endl;
            }
            flag=1;
            c=s;
            cout << s << endl;
        }
        fi.close();
        if(flag==0) {
            cout << "\nNo Student Record Present!!!" << endl;
        }
    }
    catch(exception& e)
    {
        cout << "Exception caught" << endl;
    }
}
