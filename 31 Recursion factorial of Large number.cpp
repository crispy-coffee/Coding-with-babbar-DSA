#include <bits/stdc++.h>
using namespace std;
#define ll long long
using std::to_string;


class Node
{
public:
    int data;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
    }
};

void multiply(Node *tail, int n)
{
    // cout<<"Enter" <<endl;
    Node *temp = tail, *prevNode = tail;
    int carry = 0;
    while (temp != NULL)
    {
        int data = temp->data * n + carry;
        temp->data = data % 10;
        // cout << temp->data << " ";
        carry = data / 10;
        prevNode = temp;
        temp = temp->prev;
    }

    while (carry != 0)
    {
        prevNode->prev = new Node((int)(carry % 10));
        carry /= 10;
        prevNode = prevNode->prev;
    }
}

/*

void print(Node *tail){

    if(tail == NULL)
    return ;

    print(tail->prev);
    cout << tail->data;
}

*/

void print(string &str, Node *tail)
{   
    // cout << "Entered" <<endl;
    // string str = " ";

    if (tail == NULL)
        return;

    while(tail != NULL){
        str += to_string(tail->data);
        tail = tail->prev;
    }

    reverse(str.begin(), str.end());

}

// */


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Node *head = new Node(1);
        for (int i = 2; i <= n; i++)
        {
            multiply(head, i);
            // cout<< "Helo " <<endl;
        }
        string ss = "";
        print(ss, head);
        cout << ss << endl;
        // cout << endl << "Chill" << endl;
    }

    return 0;
}