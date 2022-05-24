#include <iostream>
#include <fstream>
#include <exception>
#include "Operations.h"
using namespace std;

/** Enter student details in the file */
int Operations::EnterDetail()
{
    int check=0;
	cout << "\nEnter the student details:" << endl;
	cout << "NAME:";
	cin >> st.name;

    check=CheckName(st.name);
    if(-1==check){
        cout << "Student Detail with given Name Already present" << endl;
        return 0;
    }

    st.id=to_string(ID+vect.size()+1);
    cout << "Branch:";
    cin >> st.branch;
    cout << "Location:";
    cin >> st.location;
    
    vect.push_back(st);
    
    return 0;
}

/** Show student details for given Name */
void Operations::ShowDetail() /**< Virtual Function Definition in Derived Class */
{
    int size=vect.size();
    int is_studentdetail_present=0;
    string find_name;
    cout << "Enter the Name of Student you want to Find:" << endl;
    cin >> find_name;
    if(0==size)
    {
        cout << "No Student Record Present" << endl;
    }
    else
    {
        vector<mystruct>::iterator ptr;
        ptr=vect.begin();
        mystruct find_ptr;
        for (ptr = vect.begin(); ptr < vect.end(); ptr++)
        {
            mystruct mptr=*ptr;
            if(mptr.name==find_name){
                is_studentdetail_present=1;
                find_ptr=mptr;
                break;
            }
        }
        if(0==is_studentdetail_present){
            cout << "Student Record With Given Name Not Found" << endl;
        }
        else
        {
        cout << "\nId\tName\tBranch\tLocation" << endl;
        cout << find_ptr.id << "\t" << find_ptr.name << "\t" << find_ptr.branch << "\t" << find_ptr.location << endl;
        }
    }
}

/** Show student details for given ID */
void Operations::ShowDetail(string find_id) 
{
    int size=vect.size();
    int is_studentdetail_present=0;
    if(0==size)
    {
        cout << "No Student Record Present" << endl;
    }
    else
    {
        vector<mystruct>::iterator ptr;
        ptr=vect.begin();
        mystruct find_ptr;
        for (ptr = vect.begin(); ptr < vect.end(); ptr++)
        {
            mystruct mptr=*ptr;
            if(mptr.id==find_id){
                is_studentdetail_present=1;
                find_ptr=mptr;
                break;
            }
        }
        if(0==is_studentdetail_present){
            cout << "Student Record With Given ID Not Found" << endl;
        }
        else
        {
        cout << "\nId\tName\tBranch\tLocation" << endl;
        cout << find_ptr.id << "\t" << find_ptr.name << "\t" << find_ptr.branch << "\t" << find_ptr.location << endl;
        }
    }
}

/** Delete student details with given ID */
void Operations::DeleteDetail()
{
    int size=vect.size();
    int is_studentdetail_present=0;
    string find_name;
    cout << "Enter the Name of Student you want to delete:" << endl;
    cin >> find_name;
    if(0==size)
    {
        cout << "No Student Record Present" << endl;
    }
    else
    {
        vector<mystruct>::iterator ptr;
        ptr=vect.begin();
        for (ptr = vect.begin(); ptr < vect.end(); ptr++)
        {
            mystruct mptr=*ptr;
            //cout << mptr.branch << " " << mptr.location ;
            if(mptr.name==find_name){
                is_studentdetail_present=1;
                cout << "Following Student Detail deleted successfully" << endl;
                cout << mptr.id << "\t" << mptr.name << "\t" << mptr.branch << "\t" << mptr.location  << endl;
                vect.erase(ptr);
                break;
            }
        }
        if(0==is_studentdetail_present){
            cout << "Student Record With Given Name Not Found" << endl;
        }
    }
}