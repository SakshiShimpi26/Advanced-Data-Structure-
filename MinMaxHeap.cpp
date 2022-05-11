#include "iostream"
using namespace std;

void MaxHeapify(int arr[],int i,int size)
{
    int largest=i;
    int child1=2*i+1;
    int child2=2*i+2;

    if(child1<size && arr[largest] >arr[child1])
        largest=child1;

    if(child2<size && arr[largest] >arr[child2])
        largest=child2;

    if(largest!=i)
    {
        int temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        MaxHeapify(arr,largest,size);
    }
}

void MinHeapify(int arr[],int i,int size)
{
    int smallest=i;
    int child1=2*i+1;
    int child2=2*i+2;

    if(child1<size && arr[smallest] <arr[child1])
        smallest=child1;

    if(child2<size && arr[smallest] <arr[child2])
        smallest=child2;

    if(smallest!=i)
    {
        int temp=arr[smallest];
        arr[smallest]=arr[i];
        arr[i]=temp;
        MinHeapify(arr,smallest,size);
    }
}

void buildHeapMax(int arr[],int size)
{
    int i;
    for(i=size/2-1;i>=0;i--)
    {
        MaxHeapify(arr,i,size);
    }

    for (int i = size-1; i>0;i--)
    {
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        MaxHeapify(arr, 0, i);
    }
}

void buildHeapMin(int arr[],int size)
{
    int i;
    for(i=size/2-1;i>=0;i--)
    {
        MinHeapify(arr,i,size);
    }

    for (int i = size-1; i>0;i--)
    {
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        MinHeapify(arr, 0, i);
    }
}


int main()
{
    int n;
    cout<<"Enter Number of Elements: ";
    cin >>n;
    int arr[n];

    cout<<"Enter Elements: \n";
    for (int i= 0; i<n;i++)
    {
        int ele;
        cin>>ele;
        arr[i] = ele;
    }
    buildHeapMax(arr, n);

    cout<<"\nMAX HEAP:";
    for (int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    buildHeapMin(arr, n);
    cout<<"\n\nMIN HEAP:";
    for (int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
