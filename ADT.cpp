#include "iostream"
#include "string"
#include "stdlib.h"
using namespace std;

string newVal,search,name;
string array1[100];
string nameArray[100],finalArray[20];

int hashCode,Phone_array[10];

struct node
{
    string info;
    struct node *next;
};
struct node *start1=NULL,*new1,*head,*array2[100];

void Insert();
void Search();
void Delete();
int Digit_Extraction(int array1[]);
int main()
{
    int choice, no;

    for(int i=0;i<100;i++)
    {
        array1[i]="-1";
    }

    cout<<"How many Times You want to execute? \n";
    cin>>no;
    for(int i=0;i<no;i++)
    {
        cout<<"$$$$$$$$$MENU$$$$$$$$$$\n";
        cout<<"1. Insert Element\n";
        cout<<"2. Search Element\n";
        cout<<"3. Delete Element\n";
        cout<<"4. Exit\n";
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$\n";
        cout<<"Enter Your Choice:\n ";
        cin>>choice;

        switch(choice)
        {
            case 1:Insert();break;
            case 2:Search();break;
            case 3:Delete();break;
            case 4:cout<<"Thank You!!!!!!!";break;
        }
    }
}

void Insert()
{
    cout<<"Enter Phone Number You want to insert....\n";
    cout<<"Enter exact 10 digits of Phone Number:...\n";
    for(int i=0;i<10;i++)
    {
        cin>>Phone_array[i];
    }
    cout<<"Enter Name:...\n";
    cin>>name;

    int n1,n2,n3,n4,n5,n6,n7,n8,n9,n0;
    string ss1,ss2,ss3,ss4,ss5,ss6,ss7,ss8,ss9,ss0,final;
    n1=Phone_array[0];
    n2=Phone_array[1];
    n3=Phone_array[2];
    n4=Phone_array[3];
    n5=Phone_array[4];
    n6=Phone_array[5];
    n7=Phone_array[6];
    n8=Phone_array[7];
    n9=Phone_array[8];
    n0=Phone_array[9];

    ss1=to_string(n1);
    ss2=to_string(n2);
    ss3=to_string(n3);
    ss4=to_string(n4);
    ss5=to_string(n5);
    ss6=to_string(n6);
    ss7=to_string(n7);
    ss8=to_string(n8);
    ss9=to_string(n9);
    ss0=to_string(n0);

    final=ss1+ss2+ss3+ss4+ss5+ss6+ss7+ss8+ss9+ss0;

    int hashCode = Digit_Extraction(Phone_array);
    if(array1[hashCode]=="-1")
    {
        array1[hashCode]=final;
        cout<<"Value Inserted at index "<<hashCode<<"\n";
        nameArray[hashCode]=name;
    }
    else
    {
        struct node* new1 = new node;
        new1->info=final;
        new1->next=NULL;

        cout<<new1->info;

        array2[hashCode]=new1;
        finalArray[hashCode]=name;

    }
}

void Search()
{
    string findName;
    cout<<"Enter Name for which you want to find Phone Number.\n";
    cin>>findName;

    for(int i=0;i<100;i++)
    {
        if(nameArray[i]==findName)
        {
            cout<<"Phone Number: "<<array1[i];
            cout<<"\nName: "<<findName;
            cout<<"\n";
        }
        else
        {
            for(int i=0;i<20;i++)
            {
                if(finalArray[i]==findName)
                {
                    cout<<"Phone Number: "<<array2[i]->info;
                    cout<<"\nName: "<<finalArray[i];
                    cout<<"\n";
                }
            }
        }
    }
}

void Delete()
{
    string delName;
    cout<<"\n Enter the Name whose record you want to delete...\n";
    cin>>delName;
    for(int i=0;i<100;i++)
    {
        if(nameArray[i]==delName)
        {
            array1[i]="-1";
            nameArray[i]="-1";
            cout<<"\n Record Deleted Successfully";
        }
        else if(array2[i]->info==delName)
        {
            delete array2[i];
            finalArray[i]="-1";
            cout<<"\n Record Deleted Successfully";
        }
        else
            cout<<"\n Record Not Found\n";
    }
}

int Digit_Extraction(int array1[10])
{
    int no1=array1[2];
    int no2=array1[3];

    string s1=to_string(no1);
    string s2=to_string(no2);
    string s=s1+s2;

    int num=stoi(s);
    return num;
}

