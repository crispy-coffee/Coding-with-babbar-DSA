class Solution {
public:

    // 1 Recursion
    int Recursion(string& a, string& b, int i, int j){
        
        if(i == a.size())
            return b.size() - j;
        
        if(j == b.size())
            return a.size() - i;

        int ans = 0;
        if(a[i] == b[j]){
            ans = Recursion(a, b, i+1, j+1);
        }else{
            int insertans = 1 + Recursion(a, b, i, j+1);
            int deleteans = 1 + Recursion(a, b, i+1, j);
            int replaceans = 1 + Recursion(a, b, i+1, j+1);
            ans = min({insertans, deleteans, replaceans}) ;
        }

        return ans;
    }

    // 2 Recursion With Memoization
    int Memoization(string& a, string& b, int i, int j, vector<vector<int>>& dp){
        
        if(i == a.size())
            return b.size() - j;
        
        if(j == b.size())
            return a.size() - i;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(a[i] == b[j]){
            ans = Memoization(a, b, i+1, j+1, dp);
        }else{
            int insertans = 1 + Memoization(a, b, i, j+1, dp);
            int deleteans = 1 + Memoization(a, b, i+1, j, dp);
            int replaceans = 1 + Memoization(a, b, i+1, j+1, dp);
            ans = min({insertans, deleteans, replaceans}) ;
        }

        return dp[i][j] = ans;
    }

    // 3 Tabulation
    int Tabulation(string& a, string& b){
        int m = a.size();
        int n = b.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int j=0; j<n; j++){
            dp[m][j] = n-j;
        }

        for(int i=m-1; i>=0; i--){
             dp[i][n] = m-i;
            for(int j=n-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = dp[i+1][j+1];
                }else{
                    int insertans = 1 + dp[i][j+1];
                    int deleteans = 1 + dp[i+1][j];
                    int replaceans = 1 + dp[i+1][j+1];
                    ans = min({insertans, deleteans, replaceans}) ;
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    // 4 Space Optimization
    int SpaceOptimization(string& a, string& b){
        int m = a.size();
        int n = b.size();

        vector<int> curr(n+1, 0), next(n+1, 0);
        
        for(int j=0; j<n; j++){
            next[j] = n-j;
        }

        for(int i=m-1; i>=0; i--){
            curr[n] = m-i;
            for(int j=n-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = next[j+1];
                }else{
                    int insertans = 1 +curr[j+1];
                    int deleteans = 1 + next[j];
                    int replaceans = 1 + next[j+1];
                    ans = min({insertans, deleteans, replaceans}) ;
                }
                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }

    int minDistance(string word1, string word2) {

        // 1 Recursion
        // return Recursion(word1, word2, 0, 0);

        // 2 Recursion With Memoization
        // vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        // return Memoization(word1, word2, 0, 0, dp);

        // 3 Tabulation
        // return Tabulation(word1, word2);

        // 4 Space Optimization
        return SpaceOptimization(word1, word2);
    }
};