#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node
{
public:
    int data;
    Node *next = NULL;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertNode(Node *&head, int element, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        temp->next = temp;
    }
    else
    {

        Node *curr = head;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // temp to curr is saying tu jaha jaa rha hai vo locaiton mujhe de de
        temp->next = curr->next;
        // aur tu mere pass aaja
        curr->next = temp;
    }
}

void deletenode (Node *&head, int value)
{

    // emply list
    if (head == NULL)
    {
        cout << "List is emply" << endl;
        return;
    }
    else
    {

        Node *curr = head;
        Node *prev = NULL;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        if(prev == curr)
            head=NULL;

        else if(head==curr){
            head=prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *head)
{

    Node *temp = head;

    if (head == NULL)
    {

        cout << "Emply list" << endl;
        return;
    }

    do
    {
        cout << temp->data << " ";
        temp = temp->next;

    } while (head != temp);
    cout<< endl;
}

int main()
{

    Node *head = NULL;

    insertNode(head, 10, 5);
    print(head);
    insertNode(head, 5, 15);
    print(head);
    insertNode(head, 15, 25);
    print(head);
    insertNode(head, 25, 55);
    print(head);
    deletenode(head, 55);
    print(head);
    cout << "success " <<head->data;

    return 0;
}