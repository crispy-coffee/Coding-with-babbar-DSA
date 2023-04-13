class Solution {
public:
    // 1 Recursion
    bool Recursion(vector<int>& nums, int index, int target){
        if(target == 0)
            return true;

        if(target < 0 ||index == nums.size())
            return false;
        
        bool include = Recursion(nums, index+1, target-nums[index]);
        bool exclude = Recursion(nums, index+1, target);

        return include or exclude;
    }

    // 2 Recursion With Memoization
    bool RecursionWitheMemoization(vector<int>& nums, int index, int target, vector<vector<int>>& dp){
        if(target == 0)
            return true;

        if(target < 0 ||index == nums.size())
            return false;
        
        if(dp[index][target] != -1){
            return dp[index][target];
        }

        bool include = RecursionWitheMemoization(nums, index+1, target-nums[index], dp);
        bool exclude = RecursionWitheMemoization(nums, index+1, target, dp);

        return dp[index][target] = include or exclude;
    }

    // 3 Tabulation
    bool Tabulation(vector<int>& nums, int tar){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(tar+1, 0));
        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }

        for(int index=n-1; index>=0; index--){
            for(int target=1; target<= tar; target++){

                bool include = false;
                if(target-nums[index] >= 0)
                    include = dp[index+1][target-nums[index]];

                bool exclude = dp[index+1][target];

                dp[index][target] = include or exclude;
            }
        }

        return dp[0][tar];
    }

    // 4 Space Optimization
    bool SpaceOptimization(vector<int>& nums, int tar){
        int n = nums.size();
        vector<int> curr(tar+1, 0), next(tar+1, 0);
        
        curr[0] = 1;
        next[0] = 1;

        for(int index=n-1; index>=0; index--){
            for(int target=1; target<= tar; target++){

                bool include = false;
                if(target-nums[index] >= 0)
                    include = next[target-nums[index]];

                bool exclude = next[target];

                curr[target] = include or exclude;
            }
            next = curr;
        }

        return curr[tar];
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0){
            return false;
        }
        // 1 Recursion
        // return Recursion(nums, 0, sum/2 );

        // 2 Recursion With Memoization
        // vector<vector<int>> dp(nums.size(), vector<int>((sum/2)+1, -1));
        // return RecursionWitheMemoization(nums, 0, sum/2, dp);

        // 3 Tabulation
        // return Tabulation(nums, sum/2);

        // 4 Space Optimization
        return SpaceOptimization(nums, sum/2);
    }
};