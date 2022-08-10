#include <bits/stdc++.h>
using namespace std;
#define ll long long

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;

    LinkedListNode(T data)
    {
        this->data = data;
        next = NULL;
    }
};
void insertAthead(LinkedListNode<int> *&head, int d)
{

    LinkedListNode<int> *temp = new LinkedListNode<int>(d);
    temp->next = head;
    head = temp;
}

void print(LinkedListNode<int> *head)
{
    LinkedListNode<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    // cout <<temp->data << endl;
    cout << endl;
}

LinkedListNode<int> *reverse(LinkedListNode<int> *head)
{
    // function for reversing the linked list
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *next = curr->next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    print(prev);
    return prev;
}

void insertAtTail(LinkedListNode<int> *&head, LinkedListNode<int> *&tail, int val)
{

    LinkedListNode<int> *temp = new LinkedListNode<int>(val);
    // empty list
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

LinkedListNode<int> *add(LinkedListNode<int> *first)
{
    int carry = 1;

    LinkedListNode<int> *ansHead = NULL;
    LinkedListNode<int> *ansTail = NULL;

    while (first != NULL)
    {
        int val1 = 0;

        if (first != NULL)
            val1 = first->data;

        int sum = carry + val1;
        int digit = sum % 10;

        // create LinkedListNode<int> and add in answer Linked List
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;

        first = first->next;
    }

    //             ansTail->next = NULL;
    return ansHead;
}

void addOneToList(LinkedListNode<int> *head)
{
    //         if(head==NULL)
    //             return head;

    // reversing the LL to add the 1
    head = reverse(head);

    // sending head to the add function
    LinkedListNode<int> *ans = add(head);

    // after getting the ans reversing it again
    ans = reverse(ans);
    print(ans);
}





int main()
{

    LinkedListNode<int> *node1 = new LinkedListNode<int>(9);
    LinkedListNode<int> *head = node1;
    LinkedListNode<int> *tail = node1;
    // cout << node1->data ;

    insertAthead(head, 2);
    insertAthead(head, 4);
    // insertAthead(head, 5);
    // insertAthead(head, 6);
    // insertAthead(head, 5);
    // insertAthead(head, 8);
    // print(head);
    // insertAthead(head, 5);
    // print(head);
    // insertAthead(head, 1);
    // print(head);
    // insertAthead(head, 9);
    print(head);

    cout << endl;
    cout << endl;
    cout << endl;

    addOneToList(head);

    LinkedListNode<int> *node2 = new LinkedListNode<int>(5);
    LinkedListNode<int> *head2 = node2;
    LinkedListNode<int> *tail2 = node2;
    // cout << node1->data ;

    insertAthead(head2, 2);
    insertAthead(head2, 4);
    insertAthead(head2, 6);
    print(head2);
    // insertAthead(head, 6);
    // insertAthead(head, 5);
    // insertAthead(head, 8);
    addOneToList(head2);
    cout << "Succes" << endl;
    // insertAtTail(tail, 120);
    // print(head);

    // insertAtposition(head, 50, 20);
    // print(head);

    // insertAtposition(head, 50, 300);
    // print(head);

    // deletenode(head, tail, 30);
    // print(head);

    // deletenode(head, tail, 120);
    // print(head);

    // deletenode(head, tail, 110);
    // print(head);
    // insertAtposition(head, 20, 20);
    // print(head);

    return 0;
}