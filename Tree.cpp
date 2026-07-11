#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
class Tree
{
    Node *root;
    Node* createNode(int value)
    {
        Node *newNode = new Node;

        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }
    Node* insert(Node *root,int value)
    {
        if(root==NULL)
            return createNode(value);

        if(value < root->data)
            root->left = insert(root->left,value);

        else if(value > root->data)
            root->right = insert(root->right,value);

        return root;
    }
    Node* findMin(Node *root)
    {
        while(root->left!=NULL)
            root=root->left;

        return root;
    }
    Node* deleteNode(Node *root,int value)
    {
        if(root==NULL)
            return root;
        if(value < root->data)
            root->left=deleteNode(root->left,value);
        else if(value > root->data)
            root->right=deleteNode(root->right,value);
        else
        {
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }
            else if(root->left==NULL)
            {
                Node *temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL)
            {
                Node *temp=root->left;
                delete root;
                return temp;
            }
            Node *temp=findMin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
        return root;
    }
    void displayTree(Node *root,int space)
    {
        if(root==NULL)
            return;
        space=space+5;
        displayTree(root->right,space);
        cout<<endl;
        for(int i=5;i<space;i++)
            cout<<" ";
        cout<<root->data<<endl;
        displayTree(root->left,space);
    }
public:
    Tree()
    {
        root=NULL;
    }
    void operator <<(int value)
    {
        root=insert(root,value);

        cout<<"Node Inserted Successfully.\n";
    }
    void operator >>(int value)
    {
        root=deleteNode(root,value);

        cout<<"Node Deleted Successfully.\n";
    }
    void display()
    {
        cout<<"\nTree Structure\n";
        displayTree(root,0);
        cout<<endl;
    }
};
int main()
{
    Tree t;
    int choice,value;
    do
    {
        cout<<"\n===== MENU =====";
        cout<<"\n1. Insert";
        cout<<"\n2. Delete";
        cout<<"\n3. Display";
        cout<<"\n4. Exit";
        cout<<"\nEnter Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter Value : ";
                cin>>value;
                t<<value;
                break;
            case 2:
                cout<<"Enter Value : ";
                cin>>value;
                t>>value;
                break;
            case 3:
                t.display();
                break;
            case 4:
                cout<<"Program Ended.";
                break;
            default:
                cout<<"Invalid Choice.";
        }
    }while(choice!=4);
    return 0;
}