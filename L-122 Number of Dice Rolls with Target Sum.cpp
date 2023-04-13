#define MOD 1000000007

class Solution {
public:
    // 1 Recursion
    int Recursion(int dice, int face, int target){
        if(target == 0 and dice==0){
            return 1;
        }

        if(target<0 || dice<0 ){
            return 0;
        }

        int count = 0;
        for(int i=1; i<=face; i++){
            count += Recursion(dice-1, face, target-i);
        }

        return count;
    }

    //  2 Recursion With Memoization
    int RecursionWithMemoization(int dice, int face, int target, vector<vector<int>>& dp){
        if(target == 0 and dice==0){
            return 1;
        }

        if(target<=0 || dice<=0 ){
            return 0;
        }

        if(dp[dice][target] != -1)
            return dp[dice][target]%MOD;

        int count = 0;
        for(int i=1; i<=face; i++){
            count = (count % MOD) + RecursionWithMemoization(dice-1, face, target-i, dp) % MOD;
        }

        return dp[dice][target] = count;
    }

    // 3 Tabulation
    int Tabulation(int n, int face, int target){
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;

        for(int dice=1; dice<=n; dice++){
            for(int tar=1; tar<=target; tar++){

                int count = 0;
                for(int i=1; i<=face; i++){
                    if(tar-i >= 0)
                    count = (count % MOD) + dp[dice-1][tar-i] % MOD;
                }

                dp[dice][tar] = count;

            }
        }

        return dp[n][target] % MOD;

    }

    // 4 Space Optimization
    int SpaceOptimization(int n, int face, int target){
        
        vector<int> curr(target+1, 0), prev(target+1, 0);
        prev[0] = 1;

        for(int dice=1; dice<=n; dice++){
            for(int tar=1; tar<=target; tar++){

                int count = 0;
                for(int i=1; i<=face; i++){
                    if(tar-i >= 0)
                    count = (count % MOD) + prev[tar-i] % MOD;
                }
                curr[tar] = count;
            }
            prev = curr;
        }

        return curr[target] % MOD;

    }


    int numRollsToTarget(int n, int k, int target) {
        // 1 Recursion
        // return Recursion(n, k, target);

        // 2 Recursion With Memoization
        // vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        // return RecursionWithMemoization(n, k, target, dp);

        // 3 Tabulation
        // return Tabulation(n , k, target);

        // 4 Space Optimization
        return SpaceOptimization(n ,k, target);

    }
};