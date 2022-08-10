#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node
{

public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertAthead(Node *&head, int d)
{

    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{

    Node *e = new Node(d);
    tail->next = e;
    tail = tail->next;
}

void insertAtposition(Node *&head, int position, int d)
{

    if (head->next == NULL)
    {
        insertAthead(head, d);
    }

    Node *temp = new Node(d);
    Node *curr = head;
    while (curr->data != position)
    {
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deletenode(Node *&head, Node *&tail, int d)
{

    // Deleting head
    Node *prev = head;
    if (prev->data == d && prev->next != NULL)
    {
        head = head->next;
        prev = NULL;
        delete prev;
        return;
    }

    Node *temp = head;
    // Node* prev = NULL;
    while (temp->data != d)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        tail = prev;
    }

    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
}

int getlength(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// Normal version of finding loop in code:
bool isCircularORnot(Node *head)
{
    if (head == NULL)
        return false;

    Node *temp = head;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
        return true;
    else
        return false;
}

// map versoin of finding loop in code;
bool detectLoop(Node *head)
{

    if (head == NULL)
        return NULL;

    map<Node *, bool> visited;

    Node *temp = head;
    while (temp != NULL && visited[temp] != true)
    {

        visited[temp] = true;
        if (temp != NULL)
            temp = temp->next;
    }

    if (visited[temp] == true)
        return true;
    else
        return false;
}

// floyd cycle of finding loop;
Node *floyddetectloop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *turtle = head;
    Node *rabbit = head;

    while (rabbit != NULL && turtle != NULL)
    {
        rabbit = rabbit->next;
        if (rabbit != NULL)
            rabbit = rabbit->next;

        turtle = turtle->next;

        if (rabbit == turtle)
            return turtle;
    }
    cout << " turtle at " << turtle->data << endl;
    return NULL;
}

Node *getintersection(Node *head)
{

    Node *intersection = floyddetectloop(head);
    if (intersection == NULL)
        return NULL;

    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

Node *uniqueSortedList(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = head;
    cout << "Hello " << endl;
    while (curr != NULL)
    {
        if (curr->data == curr->next->data)
        {
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

Node *removeDuplicates(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    map<int, bool> visited;
    Node *temp = head;
    // visited[temp->data] = true;
    while (temp != NULL)
    {
        if (visited[temp->data] != true)
        {
            cout << visited[temp->data] << " ";
            visited[temp->data] = true;
            temp = temp->next;
        }
        else
        {
            //             if(temp->next==NULL)
            //                 break;
            cout << "else " << temp->data << endl;
            temp->next = temp->next->next;
        }
    }
    return head;
}

void reverseLL(Node *head, int low, int high)
{

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;
    int count = 0;

    Node *reversehead = NULL;
    Node *mainhead = NULL;

    while (count != low)
    {

        if (count != 0)
        {
            prev = curr;
            curr = curr->next;
            forward = curr->next;
        }
     
        count++;
    }

    // cout << curr->data << endl;

    // cout << "prev " <<prev->data <<endl;
    cout << "curr " << curr->data <<endl;
    cout << "foward " <<forward->data <<endl;

    mainhead = prev;
    reversehead = curr;

    for (int i = low; i <= high; i++)
    {

        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        // forward = curr->next;
    }
    if(curr == NULL)
    reversehead -> next = NULL;
    else
    reversehead -> next = curr;


    if(low==1)
    head = prev;
    else
    mainhead -> next = prev;

    cout << "prev " <<prev->data <<endl;
    // cout << "curr " << curr->data <<endl;
    // cout << "foward " <<forward->data <<endl;

       print(head);
}





int main()
{

    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;
    // cout << node1->data ;

    insertAthead(head, 4);
    insertAthead(head, 3);
    insertAthead(head, 1);

    // insertAthead(head, 2);
    // insertAthead(head, 1);
    // insertAthead(head, 50);
    // print(head);

    // insertAtTail(tail, 100);
    // print(head);

    // insertAthead(head, 40);
    // print(head);

    // insertAtTail(tail, 110);
    // print(head);

    // insertAthead(head, 30);
    // print(head);

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
    print(head);
    cout << endl;
    cout << endl;
    cout << endl;
    // Node *hope = removeDuplicates(head);
    // print(hope);

    reverseLL(head, 1, 2);

    // tail->next = head->next->next->next;
    // if (floyddetectloop(head))
    //     cout << "true" << endl;
    // else
    //     cout << "false" << endl;

    // cout << detectLoop(head) << endl;

    // Node *loop = getintersection(head);

    // cout << "Loop starts from -> " << loop->data << endl;
    // cout << endl << getlength(head) <<endl;

    // cout << "Hello" << endl;
    // cout << "Head-> " << head->data << endl;
    // cout << "Tail-> " << tail->data;

    return 0;
}