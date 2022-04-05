#include "iostream"
#include "vector"
using namespace std;
struct Node
{
    int data;
    Node* Leftptr;
    Node* Rightptr;
    bool rightThread, leftThread;

    Node() {}
    Node(int data): data(data) {}
};

Node* Insert(Node*,int);
int smallestElement(Node*);
Node* root= NULL;
Node* New;

void inorder(Node* root)
{
    if (root == nullptr) {
        return;
    }


    inorder(root->Leftptr);
    cout <<"\n"<<root->data << " ";
    inorder(root->Rightptr);
}

Node* Tree(vector<int> const &values)
{
    Node* root = nullptr;
    for (int key: values) {
        root = Insert(root, key);
    }
    return root;
}

void Thread(Node *root)
{
        if(root == NULL)
            return;

        Thread(root->Leftptr);

        if(root->Rightptr == NULL)
            root->rightThread = true;

        Thread(root->Rightptr);
    }

int main()
{
    int noOfVal,val,searchVal;
    cout<<"\n How many Values You want to Enter? \n";
    cin>>noOfVal;

    vector<int> values;

    cout<<"\nEnter "<<noOfVal<<" values: \n";
    for(int i=0;i<noOfVal;i++)
    {
        cin>>val;
        values.push_back(val);
    }

    cout<<"\n\n Inorder is:";
    Node* root = Tree(values);
    inorder(root);

    Thread(root);
    cout<<"\nAfter Making TBT : "<<endl;
    inorder(root);
}

Node* Insert(Node* root,int value)
{
    New=new Node();
    New->data=value;
    if(root==NULL)
        root=New;

    if(New->data<root->data)
    {
        if(root->Leftptr==NULL)
            root->Leftptr=New;
        else
            Insert(root->Leftptr,value);
    }

    if(root->data<New->data)
    {
        if(root->Rightptr==NULL)
            root->Rightptr=New;
        else
            Insert(root->Rightptr,value);
    }

    return root;
}


