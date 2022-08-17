#include<stack>
class SpecialStack {
    
    stack<int> s;
    int mini;
    
    // Define the data members.

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        // Implement the push() function.
        if(s.empty()){
            s.push(data);
            mini = data;
        }else{
            if(data < mini){
                s.push(2*data-mini);
                mini = data;
            }else{
                s.push(data);
            }
        }
    }

    int pop() {
        // Implement the pop() function.
        if(s.empty())
            return -1;
        int data = s.top();
        s.pop();
        if(data < mini){
            
            int prevmini = mini;
            int val = 2*mini-data;
            mini = val;
            return  prevmini;
            
        }else{
            return data;
        }
            
    }

    int top() {
        // Implement the top() function.
        if(s.empty())
            return -1;
        
        if(s.top() < mini)
            return mini;
        else
            return s.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(s.empty())
            return true;
        else
            return false;
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty())
            return -1;
        
        return mini;
            
    }  
};