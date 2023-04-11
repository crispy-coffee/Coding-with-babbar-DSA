class Solution {
public:

    // 1 Recursion
    int Recursion(vector<int>& nums, int index, int prev){
        if(index == nums.size())
            return 0;

        int include = 0; 
        if(prev == -1 || nums[prev] < nums[index]){
            include = 1 + Recursion(nums, index+1, index);
        }
        int exclude = Recursion(nums, index+1, prev);

     
        return max(exclude, include);
    }

    // 2 Recursion With Memoization
    int RecursionWithMemoization(vector<int>& nums, int index, int prev, vector<vector<int>>& dp){
        if(index == nums.size())
            return 0;

        if(dp[index][prev+1] != -1)
            return dp[index][prev+1];

        int include = 0; 
        if(prev == -1 || nums[prev] < nums[index]){
            include = 1 + RecursionWithMemoization(nums, index+1, index, dp);
        }
        int exclude = RecursionWithMemoization(nums, index+1, prev, dp);

     
        return dp[index][prev+1] = max(exclude, include);
    }

    // 3 Tabulation
    int Tabulation(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+2, 0));

        for(int index = n-1; index>=0; index--){
            for(int prev = index-1; prev>=-1; prev--){

                int include = 0; 
                if(prev == -1 || nums[prev] < nums[index]){
                    include = 1 + dp[index+1][index+1];
                }
                int exclude = dp[index+1][prev+1];

            
                dp[index][prev+1] = max(exclude, include);
            }
        }

        return dp[0][0];

    }

    // 4 Space Optimization
    int SpaceOptimization(vector<int>& nums){
        int n = nums.size();
        vector<int> curr (n+1, 0);
        vector<int> next (n+1, 0);

        for(int index = n-1; index>=0; index--){
            for(int prev = index-1; prev>=-1; prev--){

                int include = 0; 
                if(prev == -1 || nums[prev] < nums[index]){
                    include = 1 + next[index+1];
                }
                int exclude = next[prev+1];
            
                curr[prev+1] = max(exclude, include);
            }
            next = curr;
        }

        return curr[0];
    }

    // 5 Binary Search
    int binarysearch(vector<int>& nums){
        int size = nums.size();
        vector<int> ans;

        ans.push_back(nums[0]);

        for(int i=1; i<size; i++){
            if(ans.back() < nums[i])
                ans.push_back(nums[i]);
            else{
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }

        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        // 1 Recursion
        // return Recursion(nums, 0, -1);

        // 2 Recursion With Memoization
        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return RecursionWithMemoization(nums, 0, -1, dp);

        // 3 Tabulation
        // return Tabulation(nums);

        // 4 Space Optimization
        // return SpaceOptimization(nums);

        // 5 Binary Search
        return binarysearch(nums);
    }
};