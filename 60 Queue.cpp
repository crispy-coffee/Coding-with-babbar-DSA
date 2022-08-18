class Queue {
public:
    int *arr;
    int fronti;
    int rear;
    
    
    Queue() {
        arr = new int[10000];
        fronti = -1;
        rear = -1;
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
       if(rear == fronti)
           return true;
        else
            return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear < 10000){
            rear++;
            arr[rear] = data;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(rear == fronti)
            return -1;
        else{
            fronti++;
            int data = arr[fronti];
            
            return data;
        }
    }

    int front() {
        // Implement the front() function
        if(rear==fronti)
            return -1;
        else
            return arr[fronti+1];
    }
};