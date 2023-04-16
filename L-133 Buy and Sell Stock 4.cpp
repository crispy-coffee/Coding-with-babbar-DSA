class Solution {
public:
    //Frist Half Code is using Buy & Sell 2 and Buy & Sell 3's Code and use 3d dp

    /*
    // 1 Recursion
    int Recursion(vector<int>& prices, int index, bool buy, int limit){
        if(index == prices.size() || limit == 0)
            return 0;

        //Buy = True means we can buy
        int profit = 0;
        if(buy){
            int buykaro = -prices[index] +  Recursion(prices, index+1, false, limit);
            int skipkaro =  Recursion(prices, index+1, true, limit);
            profit = max(buykaro, skipkaro);
        }else{
            int sellkaro = prices[index] +  Recursion(prices, index+1, true, limit-1);
            int skipkaro =  Recursion(prices, index+1, false, limit);
            profit = max(sellkaro, skipkaro);
        }

        return profit;
    }

    // 2 Recursion With Memoization
    int Memoization(vector<int>& prices, int index, bool buy, vector<vector<vector<int>>>& dp, int limit){
        if(index == prices.size() || limit == 0)
            return 0;

        if(dp[index][buy][limit] != -1){
            return dp[index][buy][limit];
        }

        //Buy = True means we can buy
        int profit = 0;
        if(buy){
            int buykaro = -prices[index] +  Memoization(prices, index+1, false, dp, limit);
            int skipkaro =  Memoization(prices, index+1, true, dp, limit);
            profit = max(buykaro, skipkaro);
        }else{
            int sellkaro = prices[index] +  Memoization(prices, index+1, true, dp, limit-1);
            int skipkaro =  Memoization(prices, index+1, false, dp, limit);
            profit = max(sellkaro, skipkaro);
        }

        return dp[index][buy][limit] = profit;
    }

    // 3 Tabulation
    int Tabulation(vector<int>& prices, int k){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=k; limit++){
                    int profit = 0;
                    if(buy){
                        int buykaro = -prices[index] +  dp[index+1][false][limit];
                        int skipkaro = dp[index+1][true][limit];
                        profit = max(buykaro, skipkaro);
                    }else{
                        int sellkaro = prices[index] + dp[index+1][true][limit-1];
                        int skipkaro = dp[index+1][false][limit];
                        profit = max(sellkaro, skipkaro);
                    }
                    dp[index][buy][limit] = profit;
                }
            }   
        }
        return dp[0][true][k];
    }

    // 4 Space Optimization
    int SpaceOptimization(vector<int>& prices, int k){
        int n = prices.size();

        vector<vector<int>> curr(2, vector<int>(k+1,0)), next(2, vector<int>(k+1,0));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=k; limit++){
                    int profit = 0;
                    if(buy){
                        int buykaro = -prices[index] +  next[false][limit];
                        int skipkaro = next[true][limit];
                        profit = max(buykaro, skipkaro);
                    }else{
                        int sellkaro = prices[index] + next[true][limit-1];
                        int skipkaro = next[false][limit];
                        profit = max(sellkaro, skipkaro);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return curr[true][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // 1 Recursion
        // return Recursion(prices, 0, true, k);

        // 2 Recursion With Memoization
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // return Memoization(prices, 0, true, dp, k);

        // 3 Tabulation
        // return Tabulation(prices, k);

        // 4 Space Optimization
        return SpaceOptimization(prices, k);
    }
    */

    // Above Code is using Buy & Sell 2 and Buy & Sell 3's Code and use 3d dp

    // Now we optimize the Code to use 2d dp from Recursion

    // 1 Recursion
    int newRecursion(vector<int>& prices, int index, int OperationNo, int k){
        if(index == prices.size())
            return 0;
        
        if(OperationNo == 2*k)
            return 0;

        int profit = 0;
        if(OperationNo % 2 == 0){
            int buykaro = -prices[index] +  newRecursion(prices, index+1, OperationNo+1, k);
            int skipkaro =  newRecursion(prices, index+1, OperationNo, k);
            profit = max(buykaro, skipkaro);
        }else{
            int sellkaro = prices[index] +  newRecursion(prices, index+1, OperationNo+1, k);
            int skipkaro =  newRecursion(prices, index+1, OperationNo, k);
            profit = max(sellkaro, skipkaro);
        }

        return profit;
    }

    // 2 Recursion With Memoization
    int newMemoization(vector<int>& prices, int index, int OperationNo, int k, vector<vector<int>>& dp){
        if(index == prices.size())
            return 0;
        
        if(OperationNo == 2*k)
            return 0;

        if(dp[index][OperationNo] != -1)
            return dp[index][OperationNo];

        int profit = 0;
        if(OperationNo % 2 == 0){
            int buykaro = -prices[index] +  newMemoization(prices, index+1, OperationNo+1, k, dp);
            int skipkaro =  newMemoization(prices, index+1, OperationNo, k, dp);
            profit = max(buykaro, skipkaro);
        }else{
            int sellkaro = prices[index] +  newMemoization(prices, index+1, OperationNo+1, k, dp);
            int skipkaro =  newMemoization(prices, index+1, OperationNo, k, dp);
            profit = max(sellkaro, skipkaro);
        }

        return dp[index][OperationNo] = profit;
    }

    // 3 Tabulation
    int newTabulation(vector<int>& prices, int k){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>((2*k)+1, 0));

        for(int index=n-1; index>=0; index--){
            for(int OperationNo=(2*k)-1; OperationNo>=0; OperationNo--){
                int profit = 0;
                if(OperationNo % 2 == 0){
                    int buykaro = -prices[index] +  dp[index+1][OperationNo+1];
                    int skipkaro =  dp[index+1][OperationNo];
                    profit = max(buykaro, skipkaro);
                }else{
                    int sellkaro = prices[index] +  dp[index+1][OperationNo+1];
                    int skipkaro =  dp[index+1][OperationNo];
                    profit = max(sellkaro, skipkaro);
                }
                dp[index][OperationNo] = profit;
            }
        }
        return dp[0][0];
    }

    // 4 Spac eOptimization
    int newSpaceOptimization(vector<int>& prices, int k){
        int n = prices.size();
        vector<int> curr((2*k)+1, 0), next((2*k)+1, 0);

        for(int index=n-1; index>=0; index--){
            for(int OperationNo=(2*k)-1; OperationNo>=0; OperationNo--){
                int profit = 0;
                if(OperationNo % 2 == 0){
                    int buykaro = -prices[index] +  next[OperationNo+1];
                    int skipkaro =  next[OperationNo];
                    profit = max(buykaro, skipkaro);
                }else{
                    int sellkaro = prices[index] +  next[OperationNo+1];
                    int skipkaro =  next[OperationNo];
                    profit = max(sellkaro, skipkaro);
                }
                curr[OperationNo] = profit;
            }
            next = curr;
        }
        return curr[0];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // 1 Recursion
        // return newRecursion(prices, 0, 0, k);

        // 2 Recursion With Memoization
        // vector<vector<int>> dp(n+1, vector<int>((2*k)+1, -1));
        // return newMemoization(prices, 0, 0, k, dp);

        // 3 Tabulation
        // return newTabulation(prices, k);

        // 4 Space Optimization
        return newSpaceOptimization(prices, k);
    }

};