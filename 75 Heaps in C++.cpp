
// 1 Kthh Smallest element.

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        
        priority_queue<int> pq;
        
        for(int i=0; i<=r; i++){
            if(i<k){
                pq.push(arr[i]);
            }else{
                if(arr[i]<pq.top()){
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }
        return pq.top();
    }
};


// 2 Merge 2 Heaps
class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        priority_queue<int> pq;
        
        for(auto i:a){
            pq.push(i);
        }
        for(auto i:b){
            pq.push(i);
        }
        
        a.clear();
        while(!pq.empty()){
            a.push_back(pq.top());
            pq.pop();
        }
        return a;
    }
};

// 3 Is Tree a Heap:

// 4 Min Cost of "n" ropes
// 5 Convert BST into HEAP.

