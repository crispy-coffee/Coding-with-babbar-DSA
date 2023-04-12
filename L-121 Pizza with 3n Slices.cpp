class Solution {
public:
    // 1 Recursion
    int Recursion(vector<int>& slices, int index, int end, int count){
        if(count == 0 || index>end)
            return 0;

        int include = slices[index] + Recursion(slices, index+2, end, count-1);
        int exclude = Recursion(slices, index+1, end, count);

        return max(include, exclude);
    }

    // 2 Recursion With Memoization
    int RecursionWithMemoization(vector<int>& slices, int index, int end, int count, vector<vector<int>>& dp){
        if(count == 0 || index>end)
            return 0;

        if(dp[index][count] != -1)
            return dp[index][count];

        int include = slices[index] + RecursionWithMemoization(slices, index+2, end, count-1, dp);
        int exclude = RecursionWithMemoization(slices, index+1, end, count, dp);

        return dp[index][count] = max(include, exclude);
    }

    // 3 Tabulation
    int Tabulation(vector<int>& slices, int end, int start){
        int n = slices.size();
        vector<vector<int>> dp(n+2, vector<int>(n, 0));
        int slice_limit = n/3;
        for(int index = start; index>=end; index--){
            for(int count = 1; count<=slice_limit; count++){

                int include = slices[index] + dp[index+2][count-1];
                int exclude = dp[index+1][count];

                dp[index][count] = max(include, exclude);
            }
        }

        return dp[end][n/3];
    }

    // 4 Space Optimization
    int SpaceOptimization(vector<int>& slices, int end, int start){
        int n = slices.size();
        vector<int> next2(n+2, 0), next1(n+2, 0), curr(n+2, 0);
        int slice_limit = n/3;
        
        for(int index = start; index>=end; index--){
            for(int count = 1; count<=slice_limit; count++){

                int include = slices[index] + next2[count-1];
                int exclude = next1[count];

                curr[count] = max(include, exclude);
            }
            next2 = next1;
            next1 = curr;
        }

        return curr[n/3];
    }

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();

        // 1 Recursion
        // return max(Recursion(slices, 0, n-2, n/3) , Recursion(slices, 1, n-1, n/3));

        // 2 Recursion With Memoization
        // vector<vector<int>> dp1(n, vector<int>(n, -1));
        // int case1 = RecursionWithMemoization(slices, 0, n-2, n/3, dp1);
        // vector<vector<int>> dp2(n, vector<int>(n, -1));
        // int case2 = RecursionWithMemoization(slices, 1, n-1, n/3, dp2);
        // return max(case1, case2);

        // 3 Tabulation
        // int case1 = Tabulation(slices, 0, n-2);
        // int case2 = Tabulation(slices, 1, n-1);
        // return max(case1, case2);

        // 4 Space Optimization
        int case1 = SpaceOptimization(slices, 0, n-2);
        int case2 = SpaceOptimization(slices, 1, n-1);
        return max(case1, case2);
    }
};