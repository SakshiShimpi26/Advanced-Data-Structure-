#include "iostream"
#include "vector"
using namespace std;

int main()
{
    int vertices,edges;
    cout<<"\nEnter Number of Vertices in Graph: ";
    cin>>vertices;

    cout<<"\nEnter Number of Edges in Graph: ";
    cin>>edges;

    int undirected[vertices][edges];
    int source,dest;
    vector<int>graph[vertices];

    for(int j=0;j<vertices;j++)
    {
        for(int k=0;k<edges;k++)
        {
            undirected[j][k]=0;
        }
    }

   //For Undirected Graph
    for(int i=0;i<edges;i++)
    {
        cout<<"\nEnter Source Vertex     : ";
        cin>>source;
        cout<<"Enter Destination Vertex: ";
        cin>>dest;

        undirected[source][dest]=1;
        undirected[dest][source]=1;

        graph[source].push_back(dest);
        graph[dest].push_back(source);
    }

    cout<<"\n\nAJACENCY MATRIX:\n";
    for(int j=0;j<edges;j++)
    {
        for(int k=0;k<edges;k++)
        {
            cout<<undirected[j][k]<<"\t";
        }
        cout<<"\n";
    }

    //Ajacency list
    cout<<"\n\nAJACENCY LIST:\n";
    for(int i=0;i<vertices;i++)
    {
        cout<<"\nVertex "<<i<<"-->";
        for(int j = 0; j < edges; j++)
        {
            std::cout << graph[i][j] << ' ';
        }
        cout<<"\n";
    }

    return 0;
}
