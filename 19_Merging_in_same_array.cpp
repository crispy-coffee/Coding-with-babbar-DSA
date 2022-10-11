#include<bits/stdc++.h>
using namespace std;

 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=0,j=0,k=m;
        while(i<m && j<n){
            if (nums1[i]<nums2[j]){
                nums1[k+i] = nums1[i];
                k++;
                i++;
            }else{
                nums1[k+i] = nums2[j];
                k++;
                j++;
                
            }
        }

        while(i<m){
            nums1[k+i] = nums1[i];
            k++;
            i++;
        }
        
        while(j<n){
            nums1[k+j] = nums2[j];
            k++;
            j++;
        }
        
        for(int i = 0;i<nums1.size();i++){
            // nums1[i] = nums3[i];
            cout << "value of " << i << " " << nums1[i] << endl;
        }
        
    }



int main(){

    vector<int> nums1 = {1,2,3,7,8,9,0,0,0};
    vector<int> nums2 = {2,5,6};

    merge(nums1, 9, nums2, 3);

return 0;
}