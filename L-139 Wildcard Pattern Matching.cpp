class Solution {
public:
    // 1 Recursion
    int Recursion(string& s, string& p, int i, int j){

        if(i<0 and j<0){
            return true;
        }

        if(i>=0 and j<0){
            return false;
        }

        if(i<0 and j>=0){
            for(j; j>=0; j--){
                if(p[j] != '*')
                    return false;
            }
            return true;
        }

        if(s[i] == p[j] || p[j] == '?')
            return Recursion(s, p, i-1, j-1);
        else if(p[j] == '*')
            return (Recursion(s, p, i-1, j) || Recursion(s, p, i, j-1));
        else
            return false;

    }

    // 2 Recursion With Memoization
    int Memoization(string& s, string& p, int i, int j, vector<vector<int>>& dp){

        if(i<0 and j<0){
            return true;
        }

        if(i>=0 and j<0){
            return false;
        }

        if(i<0 and j>=0){
            for(j; j>=0; j--){
                if(p[j] != '*')
                    return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];

        bool ans = false;
        if(s[i] == p[j] || p[j] == '?')
            ans =  Memoization(s, p, i-1, j-1, dp);
        else if(p[j] == '*')
            ans =  (Memoization(s, p, i-1, j, dp) or Memoization(s, p, i, j-1, dp));
        else
            ans = false;

        return dp[i][j] = ans;
    }

    // 3 Recursion With Memoization with 1 base indexing
    int MemoizationBy1Base(string& s, string& p, int i, int j, vector<vector<int>>& dp){

        if(i==0 and j==0){
            return true;
        }

        if(i>0 and j==0){
            return false;
        }

        if(i==0 and j>0){
            for(j; j>0; j--){
                if(p[j-1] != '*')
                    return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];

        bool ans = false;
        if(s[i-1] == p[j-1] || p[j-1] == '?')
            ans =  MemoizationBy1Base(s, p, i-1, j-1, dp);
        else if(p[j-1] == '*')
            ans =  (MemoizationBy1Base(s, p, i-1, j, dp) or MemoizationBy1Base(s, p, i, j-1, dp));
        else
            ans = false;

        return dp[i][j] = ans;
    }

    // 4 Tabulation
    int Tabulation(string& s, string& p){
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
    
        for (int k = 1; k <= n; k++) {
            if (p[k-1] != '*') {
                dp[0][k] = false;
            } else {
                dp[0][k] = dp[0][k-1];
            }
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                bool ans = false;
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    ans =  dp[i-1][j-1];
                else if(p[j-1] == '*')
                    ans =  (dp[i-1][j] or dp[i][j-1]);
                else
                    ans = false;

                dp[i][j] = ans;
            }
        }

        return dp[m][n];
    }

    // 5 Space Optimization
    int SpaceOptimization(string& s, string& p){
        int m = s.size();
        int n = p.size();
        
        vector<int> curr(n+1, 0), prev(n+1, 0);
        prev[0] = 1;
    
        for (int k = 1; k <= n; k++) {
            if (p[k-1] != '*') {
                prev[k] = false;
            } else {
                prev[k] = prev[k-1];
            }
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                bool ans = false;
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    ans =  prev[j-1];
                else if(p[j-1] == '*')
                    ans =  (prev[j] or curr[j-1]);
                else
                    ans = false;

                curr[j] = ans;
            }
            prev = curr;
        }

        return prev[n];
    }

    bool isMatch(string s, string p) {
        
        // 1 Recursion
        // return Recursion(s, p, s.size()-1, p.size()-1);

        // 2 Recursion With Memoization
        // vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        // return Memoization(s, p, s.size()-1, p.size()-1, dp);

        // 3 Recursion With Memoization with 1 base indexing
        // vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        // return MemoizationBy1Base(s, p, s.size(), p.size(), dp);

        // 4 Tabulation
        // return Tabulation(s, p);

        // 5 Space Optimization
        return SpaceOptimization(s, p);
    }
};
