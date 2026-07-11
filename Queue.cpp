#include <iostream>
using namespace std;
class Queue
{
    int arr[10];
    int front, rear;
public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void operator <<(int value)
    {
        if(rear == 9)
        {
            cout << "Queue Overflow!" << endl;
        }
        else
        {
            if(front == -1)
                front = 0;
            rear++;
            arr[rear] = value;
            cout << value << " inserted into the queue." << endl;
        }
    }
    void operator >>(int &value)
    {
        if(front == -1 || front > rear)
        {
            cout << "Queue Underflow!" << endl;
        }
        else
        {
            value = arr[front];
            front++;
            cout << value << " deleted from the queue." << endl;
            if(front > rear)
            {
                front = rear = -1;
            }
        }
    }
    void display()
    {
        if(front == -1)
        {
            cout << "Queue is Empty." << endl;
            return;
        }

        cout << "\nQueue Elements :" << endl;

        for(int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q;
    int choice, value;
    do
    {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter value : ";
                cin >> value;
                q << value;
                break;
            case 2:
                q >> value;
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Program Ended." << endl;
                break;
            default:
                cout << "Invalid Choice!" << endl;
        }
    }while(choice != 4);
    return 0;
}