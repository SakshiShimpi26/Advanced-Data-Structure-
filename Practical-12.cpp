#include "iostream"
#include "fstream"
using namespace std;
ofstream fout ("Employee Record.txt");
ifstream fin;
class Employee
{
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

    //fout<<"\n############################ EMPLOYEE RECORDS ##########################################\n";
    //fout<<"\nID\t\tNAME\t\tDESIGNATION\t\tSALARY\n";

    for(int i=0;i<noOfEmployee;i++)
    {
        e[i].Save_Records_In_File();
    }
    //fout<<"\n#########################################################################################\n";
    fout.close();

    ifstream inFile;
    string line;
    fin.open("Employee Record.txt");
    inFile.open("Employee Record.txt");

    if(!inFile)
    {
        cout << "Unable to open file" << endl;
        exit(1);
    }

    cout<<"\nEnter Employee ID For Details: ";
    cin>>search;

    size_t pos;
    while(inFile.good())
      {
          getline(inFile,line); // get line from file
          pos=line.find(search); // search
          if(pos!=string::npos) // string::npos is returned if string is not found
          {
                cout<<"\nRecord Not Found";
          }
          else
          {
            string line;
            for(int lineno=search+1;getline(inFile,line)&&lineno<search+2;lineno++)
            {
                cout<<"\n"<<line;
            }
          }
      }

    return 0;
}
