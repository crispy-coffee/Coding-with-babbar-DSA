class Solution {
public:

    // 1 Recursion
    int Recursion(int index, int diff, vector<int>& nums){

        int ans = 0;
        int prev = nums[index];
        for(int j=index-1; j>=0; j--){
            if(prev-nums[j] == diff){
                ans++;
                prev = nums[j];
            }
        }
        
        return ans;
    }
    
    // 2 Recursion With Memoization
    int RecursionWithMemoization(int index, int diff, vector<int>& nums, vector<unordered_map<int,int>>& dp){
        if(index<0)
            return 0;
        
        if(dp[index].count(diff))
            return dp[index][diff];

        int ans = 0;
        for(int j=index-1; j>=0; j--){
            if(nums[index]-nums[j] == diff){
                ans = max(ans, 1+RecursionWithMemoization(j, diff, nums, dp));
            }
        }
        
        return dp[index][diff] = ans;
    }

    // 3 Tabulation
    int Tabulation(vector<int>& nums){
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n+1);
        int ans = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j<i; j++){
                int j_count = 1;
                int diff = nums[i]-nums[j];
                
                if(dp[j].count(diff)){
                    j_count = dp[j][diff];
                }

                dp[i][diff] = j_count + 1; // j<= se piche agr kuch huya to vo aa jayega, varna 1 hi rhega aur +1 i ka hai.
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }


    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n==2)
            return 2;
        
        int ans = 0;

        // 1 Recursion
        // for(int i=0; i<n-1; i++){
        //     for(int j=i+1; j<n; j++){
        //         ans = max(ans, 2+Recursion(i, nums[j]-nums[i], nums));
        //     }
        // }


        // 2 Recursion With Memoization
        // vector<unordered_map<int,int>> dp(n+1); // Vector with size n+1 and each block is map
        // for(int i=0; i<n-1; i++){
        //     for(int j=i+1; j<n; j++){
        //         ans = max(ans, 2+RecursionWithMemoization(i, nums[j]-nums[i], nums, dp));
        //     }
        // }

        // 3 Tabulation
        ans = Tabulation(nums);
        
        return ans;
    }

};