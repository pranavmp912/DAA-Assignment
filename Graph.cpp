#include <iostream>
using namespace std;
class Edge
{
public:
    int u, v;
};
class Graph
{
private:
    int graph[5][5];

public:
    Graph()
    {
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                graph[i][j]=0;
            }
        }
    }
    void operator <<(Edge e)
    {
        if(e.u>=0 && e.u<5 && e.v>=0 && e.v<5)
        {
            graph[e.u][e.v]=1;
            graph[e.v][e.u]=1;
            cout<<"Edge Inserted Successfully\n";
        }
        else
        {
            cout<<"Invalid Vertices\n";
        }
    }
    void operator >>(Edge e)
    {
        if(e.u>=0 && e.u<5 && e.v>=0 && e.v<5)
        {
            graph[e.u][e.v]=0;
            graph[e.v][e.u]=0;
            cout<<"Edge Deleted Successfully\n";
        }
        else
        {
            cout<<"Invalid Vertices\n";
        }
    }
    void display()
    {
        cout<<"\nAdjacency Matrix\n\n";

        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                cout<<graph[i][j]<<" ";
            }

            cout<<endl;
        }
    }
};
int main()
{
    Graph g;
    Edge e;
    int choice;
    do
    {
        cout<<"\n===== MENU =====\n";
        cout<<"1. Insert Edge\n";
        cout<<"2. Delete Edge\n";
        cout<<"3. Display Graph\n";
        cout<<"4. Exit\n";
        cout<<"Enter Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter First Vertex (0-4): ";
                cin>>e.u;
                cout<<"Enter Second Vertex (0-4): ";
                cin>>e.v;
                g<<e;
                break;
            case 2:
                cout<<"Enter First Vertex (0-4): ";
                cin>>e.u;
                cout<<"Enter Second Vertex (0-4): ";
                cin>>e.v;
                g>>e;
                break;
            case 3:
                g.display();
                break;
            case 4:
                cout<<"Program Ended.";
                break;
            default:
                cout<<"Invalid Choice";
        }
    }while(choice!=4);
    return 0;
}