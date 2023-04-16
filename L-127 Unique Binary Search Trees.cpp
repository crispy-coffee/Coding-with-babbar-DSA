class Solution {
public:
    // 1 Recursion
    int Recursion(int n){
        if(n<=1)
            return 1;

        int ans = 0;
        for(int i=1; i<=n; i++){
            ans += Recursion(i-1) * Recursion(n-i);
        }

        return ans;
    }

    // 2 Recursion With Memoization
    int RecursionWithMemoization(int n, vector<int>& dp){
        if(n<=1)
            return 1;

        if(dp[n] != -1)
            return dp[n];

        int ans = 0;
        for(int i=1; i<=n; i++){
            ans += RecursionWithMemoization(i-1, dp) * RecursionWithMemoization(n-i, dp);
        }

        return dp[n] = ans;
    }

    // 3 Tabulation
    int Tabulation(int limits){
        vector<int> dp(limits+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int n=2; n<=limits; n++){
            int ans = 0;
            for(int i=1; i<=n; i++){
                ans += dp[i-1] * dp[n-i];
            }
            dp[n] = ans;
        }
        return dp[limits];
    }

    int numTrees(int n) {
        
        // 1 Recursion
        // return Recursion(n);

        // 2 Recursion With Memoization
        // vector<int> dp(n+1, -1);
        // return RecursionWithMemoization(n ,dp);

        // 3 Tabulation
        return Tabulation(n);
    }
};