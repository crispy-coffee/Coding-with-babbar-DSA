class Queue {
public:
    int *arr;
    int fronti;
    int rear;
    
    
    Queue() {
        arr = new int[10000];
        fronti = 0;
        rear = 0;
        
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
            arr[rear] = data;
            rear++;
            
            
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(rear == fronti)
            return -1;
        else{
            int data = arr[fronti];
            arr[fronti] = -1;
            fronti++;
            return data;
        }
    }

    int front() {
        // Implement the front() function
        if(rear==fronti)
            return -1;
        else
            return arr[fronti];
    }
};