#include <iostream>
using namespace std;
class Stack
{
    int arr[10];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    bool isFull()
    {
        return (top == 9);
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    void operator <<(int value)
    {
        if(isFull())
        {
            cout << "\nERROR: Stack Overflow!" << endl;
            cout << value << " cannot be pushed because the stack is full.\n";
        }
        else
        {
            arr[++top] = value;
            cout << value << " pushed into the stack.\n";
        }
    }
    void operator >>(int &value)
    {
        if(isEmpty())
        {
            cout << "\nERROR: Stack Underflow!" << endl;
            cout << "Cannot pop because the stack is empty.\n";
        }
        else
        {
            value = arr[top--];
            cout << value << " popped from the stack.\n";
        }
    }
    void display()
    {
        if(isEmpty())
        {
            cout << "\nStack is Empty.\n";
            return;
        }
        cout << "\nStack Elements (Top to Bottom):\n";
        for(int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    Stack s;
    int choice, value;
    do
    {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s << value;
                break;
            case 2:
                s >> value;
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Program Ended.\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while(choice != 4);
    return 0;
}