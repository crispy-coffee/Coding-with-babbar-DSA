// Reverse Linked List

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *forward = NULL;
    while(curr!=NULL){
        
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
       
    }
    return prev;
}


// Middle Of Linked List

Node *findMiddle(Node *head) {
    Node* turtle = head;
    Node* rabbit = head->next;
    if(turtle==NULL || turtle->next==NULL)
        return head;
    
    while(rabbit!=NULL){
        rabbit = rabbit->next;
        if(rabbit!=NULL)
            rabbit=rabbit->next;
        
        turtle = turtle->next;       
    }
    return turtle;
}
