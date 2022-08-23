#include <bits/stdc++.h>
using namespace std;
#define ll long long

class queues
{

    int size;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;

public:
    queues(int n, int k)
    {

        size = n;

        arr = new int[size];
        front = new int[k];
        rear = new int[k];
        next = new int[size];

        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;

        freespot = 0;
    }

    void enqueue(int qn, int data)
    {

        int index = freespot;

        freespot = next[index];

        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            next[rear[qn - 1]] = index;
        }

        next[index] = -1;
        rear[qn - 1] = index;
        arr[index] = data;
        // return 0;
    }

    int dequeue(int qn)
    {
        if (front[qn - 1] == -1)
            return -1;

        int index = front[qn - 1];
        front[qn - 1] = next[index];
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};

int main()
{
    queues q(10, 5);
    q.enqueue(1, 10);
    q.enqueue(1, 20);
    q.enqueue(1, 30);
    q.enqueue(2, 40);
    q.enqueue(1, 50);
    q.enqueue(5, 60);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(5) << endl;

    return 0;
}