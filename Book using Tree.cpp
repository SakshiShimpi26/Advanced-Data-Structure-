#include "iostream"
#include "queue"
using namespace std;
struct Node
{
    string data;
    Node* Leftptr;
    Node* Rightptr;
};
void Insert(Node*,string);

Node* pointer;
Node* newNode;
Node* rootNode;
Node* new1;
Node* arr[10];

int main()
{
    string bookName,ch1,ch2,ch3,ch4;
    int level;

    cout<<"Enter Book Name: \n";
    cin>>bookName;

    rootNode= new Node();
    rootNode->data=bookName;
    rootNode->Leftptr=NULL;
    rootNode->Rightptr=NULL;
    pointer=rootNode;

    cout<<"Enter Number of Levels:";
    cin>>level;

    switch(level)
    {
        case 0:{
            cout<<bookName;
        }break;
        case 1:{
            cout<<"Enter 1 Chapters:\n";
            cin>>ch1;
            rootNode->Leftptr;
            Insert(rootNode,ch1);

            cout<<"Enter 2 Chapters:\n";
            cin>>ch2;
            rootNode->Rightptr;
            Insert(rootNode,ch2);

            cout<<"\n\t\t\t"<<bookName;
            cout<<"\n\t"<<ch1;
            cout<<"\t\t\t\t"<<ch2;
        }break;

        case 2:{
            cout<<"Enter 1 Chapters:\n";
            cin>>ch1;
            rootNode->Leftptr;
            Insert(rootNode,ch1);

            cout<<"Enter 2 Chapters:\n";
            cin>>ch2;
            rootNode->Rightptr;
            Insert(rootNode,ch2);

            cout<<"Enter Subtopic-1:\n";
            cin>>ch3;
            new1=new Node();
            new1->Leftptr;
            Insert(new1,ch1);

            cout<<"Enter Subtopic-2:\n";
            cin>>ch4;
            new1->Rightptr;
            Insert(new1,ch2);

            cout<<"\n\t\t\t\t"<<bookName;
            cout<<"\n\t\t"<<ch1;
            cout<<"\t\t\t\t\t"<<ch2;
            cout<<"\n\t"<<ch3;
            cout<<"\t\t"<<ch4;
        }break;
    }
}

void Insert(Node* rootNode1,string a)
{
    if(rootNode1->Leftptr==NULL)
    {
       newNode=new Node();
       newNode->data=a;
       newNode->Leftptr=NULL;
       newNode->Rightptr=NULL;
    }
    else if(rootNode1->Rightptr==NULL)
    {
        newNode=new Node();
        newNode->data=a;
        newNode->Leftptr=NULL;
        newNode->Rightptr=NULL;

    }
    else
        cout<<"\nEND";
}


