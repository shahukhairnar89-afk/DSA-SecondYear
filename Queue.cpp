#include <iostream>
#include <string>
using namespace std;

#define MAX 5

class Queue
{
private:
    int front, rear;
    string queue[MAX];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enQueue(string value)
    {
        // Shift elements if rear is full but there is space at the front
        if (rear == MAX - 1 && front > 0)
        {
            int j = 0;
            for (int i = front; i <= rear; i++)
            {
                queue[j++] = queue[i];
            }
            rear = rear - front;
            front = 0;
        }

        if (rear == MAX - 1)
        {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        queue[++rear] = value;
        cout << value << " inserted into queue." << endl;
    }

    void deQueue()
    {
        if (front == -1)
        {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << "Deleted element: " << queue[front] << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }

    void peek()
    {
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Front element: " << queue[front] << endl;
    }

    void viewQueue()
    {
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enQueue("Ram");
    q.enQueue("Dhruv");
    q.enQueue("Anurag");

    q.viewQueue();

    q.peek();

    q.deQueue();

    q.viewQueue();

    q.enQueue("David");
    q.enQueue("Eve");
    q.enQueue("Frank"); // Now this will be inserted after shifting

    q.viewQueue();

    return 0;
}