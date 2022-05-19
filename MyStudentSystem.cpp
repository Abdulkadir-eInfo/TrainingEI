/***********************************************************************************************************************
* Student System that stores student details in a file, retrieve it for operations
* Operations provided are: Enter Detail; Show details by ID; Delete Student details(using id);Display all student details
************************************************************************************************************************/
#include<iostream>
#include "DisplayOperations.h"
using namespace std;

/** MAIN */
int main()
{
    int choice=1;
    int count;
    cout << "Welcome to the Student System!!!!" << endl;
    DisplayAllOperation ob;  /**< Object of the DisplayAllOperations Class */
    while(choice!=6)
    {
        cout << "\nMenu:" << endl;
        cout << "1.Enter the student detail\n2.Find student\n3.Delete a Student\n4.Display All Student Details\n5.Display All Student Details(With Count)\n6.Quit" << endl;
        cout << "Enter your Choice:";
        cin >> choice;
        switch(choice)
        {
                case 1: ob.enterdetail(); //!< Entering Student details
                        break;
                case 2: ob.showdetail(); //!< Showing Student details
                        break;
                case 3: ob.deletedetail(); //!< Delete a student detail
                        break;
                case 4: ob.displayall(); //!< Display all student entries
                        break;
                case 5: count = ob.displayall(0); //!< Display all student entries with getting count of entries in return type
                        cout << "Total Student Entries :" << count << endl; 
                        break;
                case 6: cout << "Quitting you out\n";
                        break;
                default: cout << "Enter Valid Choice!!!" << endl;
                        break;
        }
    }
    return 0;
}
