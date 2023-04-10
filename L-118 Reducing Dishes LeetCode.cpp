class Solution {
public:
    // 1 Recursion
    int Recursion(vector<int>& satisfaction, int index, int time){
        if(index == satisfaction.size()){
            return 0;
        }

        int include = satisfaction[index] * (time+1) + Recursion(satisfaction, index+1, time+1);
        int exclude = 0 + Recursion(satisfaction, index+1, time);

        return max(include, exclude);
    }

    // 2 Recursion with memoization
    int RecursionWithMemoization(vector<int>& satisfaction, int index, int time, vector<vector<int>>& dp){
        if(index == satisfaction.size()){
            return 0;
        }

        if(dp[index][time] != -1){ 
            return dp[index][time];
        }

        int include = satisfaction[index] * (time+1) + RecursionWithMemoization(satisfaction, index+1, time+1, dp);
        int exclude = 0 + RecursionWithMemoization(satisfaction, index+1, time, dp);

        return dp[index][time] = max(include, exclude); 
    }

    //3 Tabulation with top down appraoch
    int Tabulation(vector<int>& satisfaction){
        int n = satisfaction.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int index = n-1; index>=0; index--){
            for(int time = index; time >=0; time--){
                int include = satisfaction[index] * (time+1) + dp[index+1][time+1];
                int exclude = 0 + dp[index+1][time];

                dp[index][time] = max(include, exclude);
            }
        }

        return dp[0][0];
        
    }

    // 4 Space Optimization
    int SpaceOptimization(vector<int>& satisfaction){
        int n = satisfaction.size();

        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for(int index = n-1; index>=0; index--){
            for(int time = index; time >=0; time--){
                int include = satisfaction[index] * (time+1) + next[time+1];
                int exclude = 0 + next[time];

                curr[time] = max(include, exclude);
            }
            next = curr;
        }

        return curr[0];
        
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        
        
        sort(begin(satisfaction), end(satisfaction));

        //1 Recursion
        // return Recursion(satisfaction, 0, 0);

        //2 Recursion with memoization
        // int n = satisfaction.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1)); //step 1
        // return RecursionWithMemoization(satisfaction, 0, 0, dp);

        //3 Tabulation Top to down
        // return Tabulation(satisfaction);

        //4 Space optimization
        return SpaceOptimization(satisfaction);
    }
};