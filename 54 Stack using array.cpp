#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        this->top = -1;
    }

    void push(int value)
    {
        if (top < size)
        {
            // top++;
            arr[++top] = value;
        }
        else
            cout << "Stack Overflow" << endl;
    }

    void pop()
    {
        if (top >= 0)
            top--;
        else
            cout << "Stack Underflow" << endl;
    }

    string isEmpty()
    {
        if (top > -1)
            return "No";
        else
            return "Yes";
    }

    int peek()
    {
        return arr[top];
    }
};

int main()
{
    Stack st(5);
    st.push(10);
    st.push(9);
    st.push(8);
    st.push(7);
    // st.pop();
    st.pop();

    cout << st.peek() << endl;
    cout << st.peek() << endl;
    cout << st.isEmpty() << endl;

    return 0;
}