class Solution {
public:
    void Sort(vector<vector<int>>& cuboids){

        for(auto& child: cuboids){
            sort(child.begin(), child.end());
        }

        sort(cuboids.begin(), cuboids.end());
    }

    bool check(vector<int>& prev, vector<int>& curr){
        if(prev[0] <= curr[0] and prev[1] <= curr[1] and prev[2] <= curr[2])
            return true;
        
        return false;
    }


    // 1 Recursion
    int Recursion(vector<vector<int>>& cuboids, int index, int prev){
        if(index == cuboids.size())
            return 0;

        int include = 0;
        if(prev == -1 || check(cuboids[prev], cuboids[index])){
            include = cuboids[index][2] + Recursion(cuboids, index+1, index);
        }
        int exclude = Recursion(cuboids, index+1, prev);

        return max(include, exclude);
    }

    // 2 Recursion With Memoization
    int RecursionWithMemoization(vector<vector<int>>& cuboids, int index, int prev, vector<vector<int>>& dp){
        if(index == cuboids.size())
            return 0;

        if(dp[index][prev+1] != -1)
            return dp[index][prev+1];

        int include = 0;
        if(prev == -1 || check(cuboids[prev], cuboids[index])){
            include = cuboids[index][2] + RecursionWithMemoization(cuboids, index+1, index, dp);
        }
        int exclude = RecursionWithMemoization(cuboids, index+1, prev, dp);

        return dp[index][prev+1] = max(include, exclude);
    }
    
    // 3 Tabulation
    int Tabulation(vector<vector<int>>& cuboids){
        int size = cuboids.size();
        vector<vector<int>> dp(size+1, vector<int>(size+1, 0));

        for(int index=size-1; index>=0; index--){
            for(int prev=index-1; prev>=-1; prev-- ){

                int include = 0;
                if(prev == -1 || check(cuboids[prev], cuboids[index])){
                    include = cuboids[index][2] + dp[index+1][index+1];
                }
                int exclude = dp[index+1][prev+1];

                dp[index][prev+1] = max(include, exclude);
            }
        }

        return dp[0][0];
    }
    
    // 4 Space Optimization
    int SpaceOptimization(vector<vector<int>>& cuboids){
        int size = cuboids.size();
        vector<int> curr(size+1, 0), next(size+1, 0);

        for(int index=size-1; index>=0; index--){
            for(int prev=index-1; prev>=-1; prev-- ){

                int include = 0;
                if(prev == -1 || check(cuboids[prev], cuboids[index])){
                    include = cuboids[index][2] + next[index+1];
                }
                int exclude = next[prev+1];

                curr[prev+1] = max(include, exclude);
            }
            next = curr;
        }

        return curr[0];
    }


    int maxHeight(vector<vector<int>>& cuboids) {
        Sort(cuboids);

        // 1 Recursion
        // return Recursion(cuboids, 0, -1);

        // 2 Recursion With Memoization
        // int size = cuboids.size();
        // vector<vector<int>> dp(size, vector<int>(size+1, -1));
        // return RecursionWithMemoization(cuboids, 0, -1, dp);

        // 3 Tabulation
        // return Tabulation(cuboids);

        // 4 Space Optimization
        return SpaceOptimization(cuboids);

    }
};