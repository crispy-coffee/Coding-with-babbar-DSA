#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev = NULL;
    Node *next = NULL;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, Node *&tail, int d)
{

    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int d)
{

    Node *temp = new Node(d);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void insertAtposition(Node *&head, Node *&tail, int position, int d)
{

    if (head == NULL || position==1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = new Node(d);
    Node *curr = head;
    int count = 0;
    
    while (count < position)
    {
        curr = curr->next;
        count++;
    }

    if (curr->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;
    temp->prev = temp;
}
    // temp->next = curr->next;
    // temp->prev = curr->next->prev;
    // curr->next = temp;
    // temp->next->prev = temp;


void print(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 50);
    print(head);
    insertAtTail(head, tail, 60);
    print(head);
    insertAtposition(head, tail, 3, 40);
    print(head);

    cout << "Head-> " << head->data << endl;
    cout << "tail-> " << tail->data << endl;

    return 0;
}