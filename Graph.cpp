#include <iostream>
using namespace std;
void insertEdge(int graph[][5],int u,int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;    
    cout << "Edge Inserted Successfully.\n";
}
void deleteEdge(int graph[][5],int u,int v)
{
    graph[u][v] = 0;
    graph[v][u] = 0;
    cout << "Edge Deleted Successfully.\n";
}
void displayGraph(int graph[][5])
{
    cout<<"\nAdjacency Matrix\n";
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int graph[5][5]={0};  
    int choice,u,v;
    do
    {
        cout << "\n===== GRAPH MENU =====";
        cout << "\n1. Insert Edge";
        cout << "\n2. Delete Edge";
        cout << "\n3. Display Graph";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter two vertices (0-4): ";
                cin>>u>>v;
                insertEdge(graph, u, v);
                break;
            case 2:
                cout<<"Enter two vertices (0-4): ";
                cin>>u>>v;
                deleteEdge(graph,u,v);
                break;
            case 3:
                displayGraph(graph);
                break;
            case 4:
                cout<<"Program Ended.\n";
                break;
            default:
                cout<<"Invalid Choice!\n";
        }
    } while(choice!=4);
    return 0;
}