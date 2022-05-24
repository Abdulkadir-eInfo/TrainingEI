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
    int count=0;
    cout << "Welcome to the Student System!!!!" << endl;
    DisplayAllOperation ob;  /**< Object of the DisplayAllOperations Class */
    
    enum MyChoice //!< enum for various choices options in the menu
    {
            ENTERDETAIL=1,
            FIND=2,
            FIND2=3,
            DELETE=4,
            DISPLAYALL=5,
            DISPLAYALL2=6,
            QUIT=7
    };

    while(7!=choice) //!< Loop until user enters 6(Choice for Quitting out)
    {
        cout << "\nMenu:" << endl;
        cout << "1.Enter the student detail\n2.Find student(By Name)\n3.Find Student(By Id)\n4.Delete a Student\n5.Display All Student Details\n6.Display All Student Details(With Count)\n7.Quit" << endl;
        cout << "Enter your Choice:";
        cin >> choice;
        string find_id;
        switch(choice)
        {
                case ENTERDETAIL:
                        ob.EnterDetail(); //!< Entering Student details
                        break;
                case FIND: 
                        ob.ShowDetail(); //!< Showing Student details by Name
                        break;
                case FIND2: 
                        cout << "Enter the Id of Student you want to Find:" << endl;
                        cin >> find_id;
                        ob.ShowDetail(find_id); //!< Showing Student details by Id
                        break;
                case DELETE: 
                        ob.DeleteDetail(); //!< Delete a student detail
                        break;
                case DISPLAYALL: 
                        ob.DisplayAll(); //!< Display all student entries
                        break;
                case DISPLAYALL2: 
                        count = ob.DisplayAll(0); //!< Display all student entries with getting count of entries in return type
                        cout << "Total Student Entries :" << count << endl; 
                        break;
                case QUIT: 
                        cout << "Quitting you out\n";
                        break;
                default: 
                        cout << "Enter Valid Choice!!!" << endl;
                        break;
        }
    }
    return 0;
}
