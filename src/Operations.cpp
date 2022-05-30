#include <iostream>
#include <fstream>
#include <exception>
#include "Operations.h"
using namespace std;

/** Used to get input of student details from User */
int Operations::InputDetail()
{
    cout << "\nEnter the student details:" << endl;
	cout << "NAME:";
	cin >> st.name;

    if(-1==CheckName(st.name)){
        cout << "Student Detail with given Name Already present" << endl;
        return FAIL;
    }

    cout << "Branch:";
    cin >> st.branch;
    cout << "Location:";
    cin >> st.location;

    return SUCCESS;
}

/** Enter student details in the file */
void Operations::EnterDetail()
{
    if(InputDetail()!=FAIL)
    {
        st.id=ID++;
        vect.push_back(st);
        SaveDataToFile();
    }
}

/** Show student details for given Name */
int Operations::ShowDetail(const string &find_name) /**< Virtual Function Definition in Derived Class */
{
    int is_studentdetail_present=0;
    if(VectorIsEmpty()!=true)
    {
        mystruct find_ptr;
        for (auto &ptr:vect)
        {
            //mystruct mptr=*ptr;
            if(ptr.name==find_name){
                is_studentdetail_present=1;
                find_ptr=ptr;
                break;
            }
        }
        if(0==is_studentdetail_present){
            cout << "Student Record With Given Name Not Found" << endl;
            return FAIL;
        }
        else
        {
        cout << "\nId\tName\tBranch\tLocation" << endl;
        cout << find_ptr.id << "\t" << find_ptr.name << "\t" << find_ptr.branch << "\t" << find_ptr.location << endl;
        return find_ptr.id;
        }
    }
    return SUCCESS;
}

/** Show student details for given ID */
void Operations::ShowDetail(int find_id) 
{
    int is_studentdetail_present=0;
    if(VectorIsEmpty()!=true)
    {
        mystruct find_ptr;
        for (auto &ptr:vect)
        {
            if(ptr.id==find_id){
                is_studentdetail_present=1;
                find_ptr=ptr;
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
    int is_studentdetail_present=0;
    string find_name;
    cout << "Enter the Name of Student you want to delete:" << endl;
    cin >> find_name;
    if(VectorIsEmpty()!=true)
    {
        vector<mystruct>::iterator ptr;
        ptr=vect.begin();
        for (ptr = vect.begin(); ptr < vect.end(); ptr++)
        {
            mystruct mptr=*ptr;
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
    if(VectorIsEmpty()!=true)
    {
        ofstream file_write;
        try
        {
            file_write.open("student.txt",ios::out);
            file_write << ID << endl;
            mystruct find_ptr;
            for (auto &ptr:vect)
            {
                file_write << ptr.id << "\t" << ptr.name << "\t" << ptr.branch << "\t" << ptr.location << "\t";
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
void Operations::UpdateDetail(const string &Update_name)
{
    string name,branch, location;
    int is_update_succesful=0;
    int Id=ShowDetail(Update_name);
    if(-1!=Id)
    {
        if(InputDetail()!=FAIL)
        {
            st.id=Id;
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
        if(is_update_succesful)
        {
            cout << "Updated Details of ID: " << st.id << " Successfully" << endl;
        }
    }
    SaveDataToFile();
}