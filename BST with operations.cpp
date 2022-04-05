#include "iostream"
#include "vector"
using namespace std;
struct Node
{
    int data;
    Node* Leftptr;
    Node* Rightptr;

    Node() {}
    Node(int data): data(data) {}
};

Node* Insert(Node*,int);
Node* Search(Node*,int);
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


int smallestElement(Node* temp){
    if(temp==NULL) {
        cout<<"Tree is empty";
        return 0;
    }
    else{
        int leftMin, rightMin;
        int min = temp->data;

        if(temp->Leftptr!= NULL){
            leftMin = smallestElement(temp->Leftptr);
            min = (min > leftMin) ? leftMin : min;
        }

        if(temp->Rightptr != NULL){
            rightMin = smallestElement(temp->Rightptr);
            min = (min > rightMin) ? rightMin : min;
        }
    return min;
    }
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

    Node* root = Tree(values);
    inorder(root);

    cout<<"\nEnter value to Search: \n";
    cin>>searchVal;
    Node* valGot=Search(root,searchVal);
    if(valGot->data==searchVal)
    {
        cout<<"\n Value Found";
    }
    else
    {
        cout<<"\n Value Not Found";
    }

    cout<<"\nSmallest element in the binary tree: "<<smallestElement(root);
    return 0;
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

Node* Search(Node* root, int key)
{
    if (root ==NULL)
    {
        cout << "Key not found";
        return NULL;
    }

    if(key<root->data)
        return Search(root->Leftptr,key);
    else if(key>root->data)
        return Search(root->Rightptr,key);
    else
        return root;
}

