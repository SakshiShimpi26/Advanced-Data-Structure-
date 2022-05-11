#include "iostream"
#include "fstream"
using namespace std;
ofstream fout ("Employee Record.txt");
ifstream fin;
class Employee
{
    public:
    int id;
    string name,designation;
    float salary;

    public:
    void getdata()
    {
        cout<<"\nEnter Employee ID  : ";
        cin>>id;
        cout<<"Enter Employee Name: ";
        cin>>name;
        cout<<"Enter Designation  : ";
        cin>>designation;
        cout<<"Enter Employee Salary: ";
        cin>>salary;
    }

    void Save_Records_In_File()
    {
        fout<<"\n"<<id<<"\t\t"<<name<<"\t\t"<<designation<<"\t\t"<<salary;
    }

    void Save_Records_In_File2()
    {
        ofstream fout2 ("Employee.txt");
        fout<<"\n"<<id<<"\t\t"<<name<<"\t\t"<<designation<<"\t\t"<<salary;
        fout2.close();
    }

    void display()
    {
        cout<<"\nEmployee Details:";
        cout<<"\nID         : "<<id;
        cout<<"\nName       :"<<name;
        cout<<"\nDesignation:"<<designation;
        cout<<"\nSalary     :"<<salary;
        cout<<"\n";
    }
};


int main()
{
    int noOfEmployee,search;
    cout<<"Enter number of Employee's record you want to store ";
    cin>>noOfEmployee;

    Employee e[noOfEmployee];
    int i;

    for(i=0;i<noOfEmployee;i++)
    {
        e[i].getdata();
    }

    fout<<"\n############################ EMPLOYEE RECORDS ##########################################\n";
    fout<<"\nID\t\tNAME\t\tDESIGNATION\t\tSALARY\n";

    for(int i=0;i<noOfEmployee;i++)
    {
        e[i].Save_Records_In_File();
    }
    fout<<"\n#########################################################################################\n";
    fout.close();

    int idToSearch;
    cout<<"\nEnter ID of Employee for Details: ";
    cin>>idToSearch;
    for(i=0;i<noOfEmployee;i++)
    {
        if(e[i].id==idToSearch)
        {
            e[i].display();
        }
    }

    int idToDelete;
    cout<<"\nEnter ID of Employee to Delete: ";
    cin>>idToDelete;
    cout<<"\nEmployee Records after Deletion:";
    for(i=0;i<noOfEmployee;i++)
    {
        if(e[i].id==idToDelete)
        {
           continue;
        }
        e[i].display();
        e[i].Save_Records_In_File2();
    }

    return 0;
}
