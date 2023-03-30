class Solution {
public:
    //15-Mar-2023
    // 1 Recursion
    int for_recusrion_only(vector<int>& cost, int n){
        if(n == 0 || n == 1) return cost[n];

        return cost[n] + min(for_recusrion_only(cost, n-1), for_recusrion_only(cost, n-2));
    }


    // 2 Recusrion with memoization
    int rec_memo(vector<int>& cost, vector<int> &dp, int n){
        if(n == 0 || n ==1) return cost[n];

        if(dp[n] != -1) return dp[n];

        dp[n] = cost[n] + min(rec_memo(cost, dp, n-1), rec_memo(cost, dp, n-2));
        return dp[n];
    }

    // 3 Tabulation (Bottom-up) Approach
    int Tabulation(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);
    }

    // 4 Space Optimised Approach
    int SpaceOptimization(vector<int>& cost) {
        int size = cost.size();
        int prev1=cost[0];
        int prev2=cost[1];
        int current = 0;
        for(int i=2; i<size; i++){
            current = cost[i] + min(prev1,prev2);
            prev1 = prev2;
            prev2 = current;
        }
        
        return min(prev1,prev2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        //1 Recursion
        // return min(for_recusrion_only(cost, n-1), for_recusrion_only(cost, n-2));

        //2 Recursion with memoization
        // vector<int> dp(n+1, -1);
        // int ans = min(rec_memo(cost, dp, n-1), rec_memo(cost, dp, n-2));
        // return ans;

        //3 Tabulation
        // return Tabulation(cost);

        //4 Space Optimization
        return SpaceOptimization(cost);

    }

};