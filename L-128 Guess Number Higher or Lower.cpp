class Solution {
public:
    // 1 Recursion
    int Recursion(int start, int end){
        if(start>=end)
            return 0;
        
        int maxi = INT_MAX;
        for(int i=start; i<=end; i++){
            maxi = min(maxi, i + max(Recursion(start,i-1), Recursion(i+1, end)));
        }
        return maxi;
    }

    // 2 Recursion With Memoization
    int RecursionWithMemoization(int start, int end, vector<vector<int>>& dp){
        if(start>=end)
            return 0;
        
        if(dp[start][end] != -1)
            return dp[start][end];

        int maxi = INT_MAX;
        for(int i=start; i<=end; i++){
            maxi = min(maxi, i + max(RecursionWithMemoization(start,i-1, dp), RecursionWithMemoization(i+1, end, dp)));
        }
        return dp[start][end] = maxi;
    }

    // 3 Tabulation
    int Tabulation(int n){
        vector<vector<int>> dp(n+2, vector<int>(n+1, 0));

        for(int start=n; start>=1; start--){
            for(int end=start; end<=n; end++){
                if(start == end)
                    continue;

                int maxi = INT_MAX;
                for(int i=start; i<=end; i++){
                    maxi = min(maxi, i + max(dp[start][i-1], dp[i+1][end]));
                }
                dp[start][end] = maxi;
            }
        }
        return dp[1][n];
    }
    
    int getMoneyAmount(int n) {

        // 1 Recursion
        // return Recursion(1, n);

        // 2 Recursion With Memoization
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return RecursionWithMemoization(1, n, dp);

        // 3 Tabulation
        return Tabulation(n);
    }
};