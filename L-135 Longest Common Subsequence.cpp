class Solution {
public:
    // 1 Recursion
    int Recursion(string& s1, string& s2, int i, int j){
        if(i == s1.size() || j == s2.size())
            return 0;
        
        if(s1[i] == s2[j])
            return 1 + Recursion(s1, s2, i+1, j+1);
        else
            return max(Recursion(s1, s2, i+1, j), Recursion(s1, s2, i, j+1));

    }

    // 2 Recursion Withe Memoization
    int Memoization(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
        if(i == s1.size() || j == s2.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(s1[i] == s2[j])
            ans =  1 + Memoization(s1, s2, i+1, j+1, dp);
        else
            ans =  max( Memoization(s1, s2, i+1, j, dp), Memoization(s1, s2, i, j+1, dp));

        return dp[i][j] = ans;
    }

    // 3 Tabulation
    int Tabulation(string& s1, string& s2){
        int n = s1.size(), m = s2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int ans = 0;
                if(s1[i] == s2[j])
                    ans =  1 + dp[i+1][j+1];
                else
                    ans =  max( dp[i+1][j], dp[i][j+1]);

                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

     // 4 Space Optimization
    int SpaceOptimization(string& s1, string& s2){
        int n = s1.size(), m = s2.size();

        vector<int> curr(m+1, 0), next(m+1, 0);

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int ans = 0;
                if(s1[i] == s2[j])
                    ans =  1 + next[j+1];
                else
                    ans =  max( next[j], curr[j+1]);

                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0];
    }

    int longestCommonSubsequence(string text1, string text2) {

        // 1 Recursion
        // return Recursion(text1, text2, 0, 0);

        // 2 Recursion Withe Memoization
        // int n = text1.size(), m = text2.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return Memoization(text1, text2, 0, 0, dp);

        // 3 Tabulation
        // return Tabulation(text1, text2);

        // 4 Space Optimization
        return SpaceOptimization(text1, text2);
       
    }
};