class Solution {
public:
    // 1 Recursion
    int Recursion(vector<int>& values, int i, int j){
        if(i+1 == j) 
            return 0;

        int mini = INT_MAX;
        for(int k=i+1; k<j; k++){
            mini = min(mini, values[i]*values[k]*values[j] + Recursion(values, i, k) + Recursion(values, k, j));
        }

        return mini;
    }

    // 2 Recursion With Memoization
    int RecursionWithMemoization(vector<int>& values, int i, int j, vector<vector<int>>& dp){
        if(i+1 == j) 
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;
        for(int k=i+1; k<j; k++){
            mini = min(mini, values[i]*values[k]*values[j] + RecursionWithMemoization(values, i, k, dp) + RecursionWithMemoization(values, k, j, dp));
        }

        return dp[i][j] = mini;
    }

    // 3 Tabulation
    int Tabulation(vector<int>& values){
        int size = values.size();
        vector<vector<int>>dp(size, vector<int>(size, 0));

        for(int i=size-1; i>=0; i--){
            for(int j= i+2; j<size; j++){
                int mini = INT_MAX;
                for(int k=i+1; k<j; k++){
                    mini = min(mini, values[i]*values[k]*values[j] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = mini;
            }
        }

        return dp[0][size-1];

    }

    int minScoreTriangulation(vector<int>& values) {
        int size = values.size();

        // 1 Recursion
        // return Recursion(values, 0, size-1);

        // 2 Recursion With Memoization
        // vector<vector<int>>dp(size+1, vector<int>(size+1, -1));
        // return RecursionWithMemoization(values, 0, size-1, dp);

        // 3 Tabulation
        return Tabulation(values);

    }
};