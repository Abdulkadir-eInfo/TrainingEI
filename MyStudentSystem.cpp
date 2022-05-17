/***********************************************************************************************************************
* Student System that stores student details in a file, retrieve it for operations
* Operations provided are: Enter Detail; Show details by ID; Delete Student details(using id);Display all student details
************************************************************************************************************************/
#include<iostream>
#include "Operations.h"
using namespace std;

/** MAIN */
int main()
{
    int choice=1;
    cout << "Welcome to the Student System!!!!" << endl;
    Operations ob;  /**< Object of the Operations Class */
    while(choice!=5)
    {
        cout << "\nMenu:" << endl;
        cout << "1.Enter the student detail\n2.Find student\n3.Delete a Student\n4.Display All Student Details\n5.Quit" << endl;
        cout << "Enter your Choice:";
        cin >> choice;
        switch(choice)
        {
            case 1: ob.enterdetail();
                    break;
            case 2: ob.showdetail();
                    break;
            case 3: ob.deletedetail();
                    break;
            case 4: ob.displayall();
                    break;
            case 5: cout << "Quitting you out\n";
                    break;
            default: cout << "Enter Valid Choice!!!" << endl;
                    break;
        }
    }
    return 0;
}
