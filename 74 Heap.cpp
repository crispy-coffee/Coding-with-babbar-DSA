#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Heap{
    public:
    int arr[100];
    int size;

    Heap(){
        arr[0] = -1;
        size = 0;
    }

    void insertion(int val){
        size += 1;
        int index = size;
        arr[index] = val;

         while(index>1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }else{
                break;
            }
         }
    }
 
    void print(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }

    void deletion(int i){
        if(size == 0){
            cout << "nothing to delete";
            return;
        }

        swap(arr[i],arr[size]);
        size -=1;
        while(i<size){
            int leftchild = 2*i;
            int rightchild = 2*i+1;

            if(leftchild < size && arr[i]<arr[leftchild]){
                swap(arr[i],arr[leftchild]);
                i = leftchild;
            }else if(rightchild < size && arr[i]<arr[rightchild]){
                swap(arr[i],arr[rightchild]);
                i = rightchild;
            }else{
                return;
            }
            
        }
    }   

};

void heapify(int *arr, int size, int i){

    int largest = i;
    int left = 2*i;
    int right = 2*i+1;


    if(left < size && arr[largest] < arr[left]){
        largest = left;
    }
     
    if(right < size && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }

}

void sorting(int *arr, int size){
    if(size == 0){
        return;
    }
    int index = size;
    while(size>0){
        swap(arr[1], arr[size]);
        size-- ;
        heapify(arr,size, 1);
    }

    return;

}

int main(){

    Heap h;
    // h.insertion(50);
    // h.insertion(60);
    // h.insertion(40);
    // h.insertion(56);
    // h.insertion(55);
    
    // h.print();
    // h.deletion(3);
    // h.print();

    int ary[10] = {-1, 6 ,7 ,5 ,4 ,9 ,2, 1, 8, 3};
    int n=9;
    for(int i=1; i<=n; i++){
        h.insertion(ary[i]);
    }
    // int ary[6] = {-1,54,53,55,52,50};
    // int n = 5;

    /*for(int i=n/2; i>0; i--){
        // cout << "1 " << i << " \n";
        heapify(ary, n, i);
    }
    */
   sorting(ary, n);

    for(int i=1; i<=n; i++){
        cout << ary[i] << " ";
    }



return 0;
}