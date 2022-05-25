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

    st.id=ID++;
    cout << "Branch:";
    cin >> st.branch;
    cout << "Location:";
    cin >> st.location;
    
    vect.push_back(st);
    SaveDataToFile();
    return 0;
}

/** Show student details for given Name */
int Operations::ShowDetail(string find_name) /**< Virtual Function Definition in Derived Class */
{
    int size=vect.size();
    int is_studentdetail_present=0;
    
    if(0==size)
    {
        cout << "No Student Record Present" << endl;
        return -1;
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
            return -1;
        }
        else
        {
        cout << "\nId\tName\tBranch\tLocation" << endl;
        cout << find_ptr.id << "\t" << find_ptr.name << "\t" << find_ptr.branch << "\t" << find_ptr.location << endl;
        return find_ptr.id;
        }
    }
}

/** Show student details for given ID */
void Operations::ShowDetail(int find_id) 
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
    SaveDataToFile();
}

/** Saves data from the vector to txt file */
void Operations::SaveDataToFile()
{
    int size=vect.size();
    if(0!=size)
    {
        ofstream file_write;
        try
        {
            file_write.open("student.txt",ios::out);
            file_write << ID << endl;
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

/** Updates Student Details with new details entered by User */
void Operations::UpdateDetail(string Update_name)
{
    string name,branch, location;
    int is_update_succesful=0;
    st.id=ShowDetail(Update_name);
    if(-1!=st.id)
    {
        cout << "Enter Updated Details:" << endl;
        cout << "NAME:";
        cin >> st.name;
        cout << "Branch:";
        cin >> st.branch;
        cout << "Location:";
        cin >> st.location;
        vector<mystruct>::iterator ptr;
        ptr=vect.begin();
        for (ptr = vect.begin(); ptr < vect.end(); ptr++)
        {
            mystruct mptr=*ptr;
            if(mptr.id==st.id){
                is_update_succesful=1;
                vect.erase(ptr);
                vect.insert(ptr,st);
                break;
            }
        }
    }
    SaveDataToFile();
}