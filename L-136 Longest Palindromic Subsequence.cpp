class Solution {
public:

    // 1 Recursion
    int Recursion(string& s, int start, int end){
        if(start > end)
            return 0;
        
        if(start == end)
            return 1;
        
        int ans = 1;
        if(s[start] == s[end]){
            ans = 2 + Recursion(s, start+1, end-1);
        }else{
            ans = max(Recursion(s, start+1, end), Recursion(s, start, end-1));
        }
        return ans;
    }

    // 2 Recursion With Memoization
    int Memoization(string& s, int start, int end,  vector<vector<int>>& dp){
        if(start > end)
            return 0;

        if(start == end)
            return 1;

        if(dp[start][end] != -1)
            return dp[start][end];

        int ans = 1;
        if(s[start] == s[end]){
            ans = 2 + Memoization(s, start+1, end-1, dp);
        }else{
            ans = max(Memoization(s, start+1, end, dp), Memoization(s, start, end-1, dp));
        }

        return dp[start][end] = ans;
    }

    // 3 Tabulation
    int Tabulation(string& s){
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=0; i<=n; i++)
            dp[i][i] = 1;  

        for(int start = n-1; start >= 0; start--){
            for(int end = start+1; end <= n-1; end++){
                
                int ans = 1;
                if(s[start] == s[end]){
                    ans = 2 + dp[start+1][end-1];
                }else{
                    ans = max(dp[start+1][end], dp[start][end-1]);
                }
                dp[start][end] = ans;
            }
        }
        return dp[0][n-1];
    }

    // 4 Space Optimization
    int SpaceOptimization(string& s){
        int n = s.size();
        vector<int> curr(n+1, 0), next(n+1, 1);

        for(int start = n-1; start >= 0; start--){
            curr[start] = 1;
            for(int end = start+1; end <= n-1; end++){
                int ans = 1;
                if(s[start] == s[end]){
                    ans = 2 + next[end-1];
                }else{
                    ans = max(next[end], curr[end-1]);
                }
                curr[end] = ans;
            }
            next = curr;
        }
        return curr[n-1];
    }

    int longestPalindromeSubseq(string& s) {
        int n = s.size();
        // Another approach for solving this is to use (s1, reverse_of_s1) and apply Longest common subsequence
        // 1 Recursion
        // return Recursion(s, 0, n-1);

        // 2 Recursion With Memoization
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return Memoization(s, 0, n-1, dp);

        // 3 Tabulation
        // return Tabulation(s);

        // 4 Space Optimization
        return SpaceOptimization(s);

    }
};