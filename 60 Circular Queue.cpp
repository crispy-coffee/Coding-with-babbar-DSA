    class CircularQueue{
    public:
    
    int *arr;
    int front;
    int rear;
    int size;
    
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        
        if(front == -1){
            front = rear = 0;
        }else if(front == 0 && rear == size-1 || rear == front-1){
            return false;
        }else if(rear == size-1 && front != 0){
            rear = 0;
        }else{
            rear ++;
        }
        arr[rear] = value;
        return true;
        
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        int val = 0;
       if(front == -1){
           return -1;
       }else if(front == rear){
           val = arr[front];
           front = rear = -1;
       }else if(front == size-1 && rear != 0){
           val = arr[front];
           front = 0;
       }else{
           val = arr[front];
           front++ ;
       }
        return val;
    }
};