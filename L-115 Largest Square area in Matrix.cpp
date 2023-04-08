class Solution {
public:
    // 1 Recursion
    int Recursion(vector<vector<char>>& matrix, int i, int j, int& maxi){
        if(i >= matrix.size() || j >= matrix[0].size())
            return 0;

        int right = Recursion(matrix, i, j+1, maxi);
        int diagonal = Recursion(matrix, i+1, j+1, maxi);
        int down = Recursion(matrix, i+1, j, maxi);

        if(matrix[i][j] == '1'){
            int ans = 1+min({right, diagonal, down});
            maxi = max(maxi, ans);
            return ans;

        }else{
            return 0;
        }
        
    }

    // 2 Recursion With Memoization
    int RecursionWithMemoization(vector<vector<char>>& matrix, int i, int j, int& maxi,  vector<vector<int>>& dp){
        if(i >= matrix.size() || j >= matrix[0].size())
            return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = RecursionWithMemoization(matrix, i, j+1, maxi, dp) ;
        int diagonal = RecursionWithMemoization(matrix, i+1, j+1, maxi, dp);
        int down = RecursionWithMemoization(matrix, i+1, j, maxi, dp);

        if(matrix[i][j] == '1'){
            dp[i][j] = 1+min({right, diagonal, down});
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }else{
            return 0;
        }
    }

    // 3 Tabulation
    int Tabulation(vector<vector<char>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        int maxi = INT_MIN;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){

                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];

                if(matrix[i][j] == '1'){
                    dp[i][j] = 1+min({right, diagonal, down});
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }

        if(maxi != INT_MIN)
            return maxi*maxi;

        return 0;
    }

    int SpaceOptimization(vector<vector<char>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);

        int maxi = INT_MIN;
        for(int i=n-1; i>=0; i--){
            vector<int> curr(m+1, 0); // hr baar curr ka data next me ja rha hai to curr ko refresh hona hai  
            // either do this or add "else" after if in which add curr[j] = 0;
            for(int j=m-1; j>=0; j--){

                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];

                if(matrix[i][j] == '1'){
                    curr[j] = 1+min({right, diagonal, down});
                    maxi = max(maxi, curr[j]);
                }
            }
            next = curr;
        }

        if(maxi != INT_MIN)
            return maxi*maxi;

        return 0;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;

        // 1 Recursion
        // Recursion(matrix, 0, 0, maxi);
        // return maxi*maxi;

        // 2 Recursion With Memoization
        // vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        // RecursionWithMemoization(matrix, 0, 0, maxi, dp);
        // return maxi*maxi;

        //3 Tabulation
        // return Tabulation(matrix);

        // 4 Space Optimization
        return SpaceOptimization(matrix);

    }
};