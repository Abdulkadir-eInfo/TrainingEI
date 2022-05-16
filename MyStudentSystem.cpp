//Student System that stores student details in a file, retrieve it for operations
//Operations provided are: Enter Detail; Show details by ID; Delete Student details(using id);Display all student details
#include<iostream>
#include<cstring>
#include<fstream>
#include<exception>
using namespace std;

class BaseClass{
    public:
    //Displays all the student entries
    inline void displayall()
    {
        string s,c;
        int flag=0;//check if there is user entry present or not
        fstream fi;
        try{
        fi.open("student.txt",ios::in);
        
        
        //Getting each line in a string and print it.
        while ( getline(fi,s) )
                {   if(flag==0)
                    {
                        //print the header line for the first time only
                        cout << "\nId\tName\tBranch\tLocation" << endl;
                        }
                    flag=1;
                    c=s;
                    cout << s << endl;
                }
        fi.close();
        if(flag==0){
            cout << "\nNo Student Record Present!!!" << endl;
        }
        }

        catch(exception& e){
            cout << "Exception caught" << endl;
        }
    }
    


};
//End of Base class 

//MyClass inherits BaseClass publically
class MyClass:public BaseClass{
    public:

    //Enter student details in the file
    int enterdetail()
    {
        string i,id;
		char name[20],location[15],branch[10];
		cout << "\nEnter the student details:" << endl;
		cout << "ID(1 to 999):";
		cin >> i;
        if(i=="0"){
            cout << "\nInvalid Input, ID must be between 1 to 999 only\n" << endl;
            return 0;
        }

        //Removing unnecessary leading zeros for eg. 0001, 00000001 etc. to get 1 only
        i.erase(0, i.find_first_not_of('0'));
        //Converting input id to standard form i.e. 001,011,111
        if(i.length()>3 || i.length()==0){
            cout << "\nInvalid Input, ID must be between 001 to 999 only" << endl;
            return 0;
        }
        
        if(i.length()==2){
            id = "0"+i;
        }
        else if(i.length()==1){
            id = "00"+i;
        }
        else{
            id=i;
        }
        //Checking if the student details with given id already exists!!!
        ifstream fi;
        string c,s,check;
        int y=0;
    
        fi.open("student.txt",ios::in);
        //loop will run until we get line copied into the string i.e. until we reach last line
        while ( getline(fi,s) )
                {   c=s;
                    //get first three characters from the line(which will contain the id of the student)
                    check=c.substr(0,3);
                    //Check if user provided id and id of the student entry is same or not.
                    if(check==id)
                    {
                    y=1;
                    break;
                    }
                }
        fi.close();
        //If there exists a Student entry with the user-input id
        //ID will be unique for each student
        if(y==1){
            cout << "Student Data with given id already exists" << endl;
            return -1;
        }

        cout << "Name:";
        cin >> name;
        cout << "Branch:";
        cin >> branch;
        cout << "Location:";
        cin >> location;
        ofstream fo;
        
        //Exception Handling to handle file exceptions
        try{
        fo.open("student.txt",ios::app);
        
        fo << id << "\t" << name << "\t" << branch << "\t" << location << endl;

        //Checking for good bit
        //The good( ) function returns a non-zero (true) value when no error has occurred; otherwise returns zero (false).
        if(fo.good())
        cout << "Student Data Inserted Successfully" << endl;
        fo.close();
        
        }
        catch(exception& e){
            cout << "Exception caught" << endl;
        }
        return 0;

    }

    //Show student details for given ID, reading from file
    void showdetail()
    {
        int y=0;
        string x,i;
        string s,c,check;
        char ch[30];
        cout << "\nEnter the id of the student you want to show data: ";
        cin >> i;
        //Converting input id to standard form i.e. 001,011,111 for proper checking with stduent entries present.
        if(i.length()==2){
            x = "0"+i;
        }
        else if(i.length()==1){
            x = "00"+i;
        }
        else{
            x=i;
        }
        ifstream fi;

        //Exception Handling to handle file exceptions
        try{
        fi.open("student.txt",ios::in);

        
        while ( getline(fi,s) )
                {   
                    c=s;

                    check=c.substr(0,3);
                    if(check==x)
                    {
                    y=1;
                    cout << "\nId\tName\tBranch\tLocation" << endl;
                    cout << s << endl;
                    }
                }
        fi.close();
        if(y==0)
            cout << "Student record not found!!!" << endl;
        }

        catch(exception& e){
            cout << "Exception caught" << endl;
        }

    }

    //Delete student details with given ID
    void deletedetail(){
        int y=0;
        string s,c,d,x,check,i;
        char ch[30];
        cout << "\nEnter the id of the student you want to delete: ";
        cin >> i;
        if(i.length()==2){
            x = "0"+i;
        }
        else if(i.length()==1){
            x = "00"+i;
        }
        else{
            x=i;
        }
        ifstream fi;
        ofstream fo;

        //Exception Handling to handle file exceptions
        try{
        fi.open("student.txt",ios::in);
        fo.open("studentbckp.txt",ios::out);
        while ( getline(fi,s) )
                {   
                c=s;
                
                check=c.substr(0,3);
                //If the id is same as the id provided by user, the entry of that student in studentbckp.txt will be skipped.
                    if(check==x)
                    {
                    y=1;
                    d=c;
                    continue;
                    }
                fo << c << "\n";
                }
        fi.close();
        fo.close();

        //Copying data from backup to back into the original file
        fi.open("studentbckp.txt",ios::in);
        fo.open("student.txt",ios::out);
        while ( getline(fi,s) )
                {   
                c=s;
                fo << c << "\n";
                }
        fi.close();
        fo.close();
        if(y==0)
            cout << "Student record not found!!!" << endl;
        else if(y==1)
           cout << "\nFollowing record of Student deleted successfully:\n" << d << endl; 
        }

        catch(exception& e){
            cout << "Exception caught" << endl; 
        }

    }
};
//End of MyClass

//MAIN
int main(){
   int ch=1;
   cout << "Welcome to the Student System!!!!" << endl;
   MyClass ob;//Object of the MyClass.
   while(ch!=5)
      {
      cout << "\nMenu:" << endl;
      cout << "1.Enter the student detail\n2.Find student\n3.Delete a Student\n4.Display All Student Details\n5.Quit" << endl;
      cout << "Enter your Choice:";
      cin >> ch;
      switch(ch){
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