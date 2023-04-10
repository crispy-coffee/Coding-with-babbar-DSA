class Solution {
public: 
    // 1 Recursion
    int Recursion(vector<int>& obstacles, int lane, int position){
        if(position == obstacles.size()-1){
            return 0;
        }
        
        
        if(obstacles[position+1] != lane){
            return Recursion(obstacles, lane, position+1);
        }else{
            
            int ans = INT_MAX;
            for(int i=1; i<=3; i++){
                if(obstacles[position] != i and i != lane){
                    ans = min(ans, 1+Recursion(obstacles, i, position));
                }
            }
            return ans;
        }

        return -1;
    }

    // 2 Recursion With Memoization
    int RecursionWithMemoization(vector<int>& obstacles, int lane, int position, vector<vector<int>>& dp){
        if(position == obstacles.size()-1){
            return 0;
        }
        
        if(dp[lane][position] != -1){
            return dp[lane][position];
        }
        
        if(obstacles[position+1] != lane){
            return RecursionWithMemoization(obstacles, lane, position+1, dp);
        }else{
            
            int ans = INT_MAX;
            for(int i=1; i<=3; i++){
                if(obstacles[position] != i and i != lane){
                    ans = min(ans, 1+RecursionWithMemoization(obstacles, i, position, dp));
                }
            }
            return dp[lane][position] = ans;
        }

        return -1;
    }
    
    // 3 Tabulation
    int Tabulation(vector<int>& obstacles){
        int n = obstacles.size()-1;
        vector<vector<int>> dp(4, vector<int>(n+1, 1e9));
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for(int position=n-1; position>=0; position--){
            for(int lane=1; lane<=3; lane++){

                if(obstacles[position+1] != lane){
                    dp[lane][position] = dp[lane][position+1];
                }else{
                    
                    int ans = 1e9;
                    for(int i=1; i<=3; i++){
                        if(obstacles[position] != i and i != lane){
                            ans = min(ans, 1+dp[i][position+1]);
                        } // in Tab why we add +1 in dp position? we are actually solving this qstn from 1st to 3rd lane 
                        // what if i am at pos 2 and getting the answer of 3rd lange? there is INT_MAX aur 3rd ka asnwer 
                        // abhi tk nikala hi nhi hai maine to, isiliye uske aage wale se answer le liya maine yaha pr
                    }
                    dp[lane][position] = ans;
                }
            }
        }

        return min({dp[1][0]+1, dp[2][0], dp[3][0]+1});

    }

    // 4 Space Optimization
    int SpaceOptimization(vector<int>& obstacles){
        int n = obstacles.size()-1;

        vector<int> curr(4, 1e9);
        vector<int> next(4, 0);

        for(int position=n-1; position>=0; position--){
            for(int lane=1; lane<=3; lane++){

                if(obstacles[position+1] != lane){
                    curr[lane] = next[lane];
                }else{
                    
                    int ans = 1e9;
                    for(int i=1; i<=3; i++){
                        if(obstacles[position] != i and i != lane){
                            ans = min(ans, 1+next[i]);
                        }
                    }
                    curr[lane] = ans;
                }
            }
            next = curr;
        }

        return min({curr[1]+1, curr[2], curr[0]+1});

    }


    int minSideJumps(vector<int>& obstacles) {
        // 1 Recursion
        // return Recursion(obstacles, 2, 0);

        // 2 Recursion With Memoization
        // vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        // return RecursionWithMemoization(obstacles, 2, 0, dp);

        // 3 Tabulation
        // return Tabulation(obstacles);

        // 4 Space Optimization
        return SpaceOptimization(obstacles);

    }
};