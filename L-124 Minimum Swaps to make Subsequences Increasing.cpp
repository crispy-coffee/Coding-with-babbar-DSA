class Solution {
public:
    // 1 Recursion
    int Recursion(vector<int>& nums1, vector<int>& nums2, int index, bool swapped){
        if(index >= nums1.size())
            return 0;
        
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        if(swapped){
            swap(prev1, prev2);
        }
        int ans = INT_MAX;
         
        if(prev1 < nums1[index] and prev2 < nums2[index]){
            ans = Recursion(nums1, nums2, index+1, false);
        }

        if(prev2 < nums1[index] and prev1 < nums2[index]){
            ans = min(ans, 1 + Recursion(nums1, nums2, index+1, true));
        }

        return ans;
    }

    // 2 Recursion With Memoization

    int RecursionWithMemoization(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>>& dp){
        if(index == nums1.size())
            return 0;
        
        if(dp[index][swapped] != -1){
            return dp[index][swapped];
        }

        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        if(swapped){
            swap(prev1, prev2);
        }
        int ans = INT_MAX;
         
        if(prev1 < nums1[index] and prev2 < nums2[index]){
            ans = RecursionWithMemoization(nums1, nums2, index+1, false, dp);
        }

        if(prev2 < nums1[index] and prev1 < nums2[index]){
            ans = min(ans, 1 + RecursionWithMemoization(nums1, nums2, index+1, true, dp));
        }

        return dp[index][swapped] = ans;
    }

    // 3 Tabulation
    int Tabulation(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int index = n-1; index>=1; index--){
            for(int swapped = 1; swapped>=0; swapped--){

                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                if(swapped){
                    swap(prev1, prev2);
                }
                int ans = INT_MAX;
                
                if(prev1 < nums1[index] and prev2 < nums2[index]){
                    ans = dp[index+1][0];
                }

                if(prev2 < nums1[index] and prev1 < nums2[index]){
                    ans = min(ans, 1 + dp[index+1][1]);
                }

                dp[index][swapped] = ans;
            }
        }

        return dp[1][0];

    }

    // 4 Space Optimization
    int SpaceOptimization(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        
        vector<int> curr(2,0), next(2,0);
        for(int index = n-1; index>=1; index--){
            for(int swapped = 1; swapped>=0; swapped--){

                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                if(swapped){
                    swap(prev1, prev2);
                }
                int ans = INT_MAX;
                
                if(prev1 < nums1[index] and prev2 < nums2[index]){
                    ans = next[0];
                }

                if(prev2 < nums1[index] and prev1 < nums2[index]){
                    ans = min(ans, 1 + next[1]);
                }

                curr[swapped] = ans;
            }
            next = curr;
        }

        return curr[0];
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // 1 Recursion
        // return Recursion(nums1, nums2, 1, false);

        // 2 Recursion With Memoization
        // int n = nums1.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return RecursionWithMemoization(nums1, nums2, 1, false, dp);

        // 3 Tabulation
        // return Tabulation(nums1, nums2);

        // 4 Space Optimization
        return SpaceOptimization(nums1, nums2);
    }
};