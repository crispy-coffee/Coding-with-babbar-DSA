#include<bits/stdc++.h>

Node *removeDuplicates(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    unordered_map<int , bool> visited;
    Node *prev = head;
    Node *curr = head->next;
    visited[prev->data]=true;
    while (curr!= NULL )
    {
        if (visited[curr->data] == true){
            prev->next = curr->next;
            delete(curr);
          
        }else
        {
            visited[curr->data] = true;
            prev = prev->next;
            
        }curr = prev->next;
       
    }
    return head;
}

// O(n^2)
Node *removeDuplicates(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = head;
    while (curr != NULL)
    {

        Node *temp = curr->next;
        while (temp != NULL)
        {
            if (curr->data == temp->data)
            {
                curr->next = temp->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}
