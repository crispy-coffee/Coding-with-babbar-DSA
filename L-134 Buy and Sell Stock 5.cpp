class Solution {
public:
    // 1 Recursion
    int Recursion(vector<int>& prices, int index, bool buy, int fee){
        if(index == prices.size())
            return 0;

        //Buy = True means we can buy
        int profit = 0;
        if(buy){
            int buykaro = -prices[index] +  Recursion(prices, index+1, false, fee);
            int skipkaro =  Recursion(prices, index+1, true, fee);
            profit = max(buykaro, skipkaro);
        }else{
            int sellkaro = prices[index] - fee +  Recursion(prices, index+1, true, fee);
            int skipkaro =  Recursion(prices, index+1, false, fee);
            profit = max(sellkaro, skipkaro);
        }

        return profit;
    }

    // 2 Recursion With Memoization
    int Memoization(vector<int>& prices, int index, bool buy, vector<vector<int>>& dp, int fee){
        if(index == prices.size())
            return 0;

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        //Buy = True means we can buy
        int profit = 0;
        if(buy){
            int buykaro = -prices[index] +  Memoization(prices, index+1, false, dp, fee);
            int skipkaro =  Memoization(prices, index+1, true, dp, fee);
            profit = max(buykaro, skipkaro);
        }else{
            int sellkaro = prices[index] - fee +  Memoization(prices, index+1, true, dp, fee);
            int skipkaro =  Memoization(prices, index+1, false, dp, fee);
            profit = max(sellkaro, skipkaro);
        }

        return dp[index][buy] = profit;
    }

    // 3 Tabulation
    int Tabulation(vector<int>& prices, int fee){
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;
                if(buy){
                    int buykaro = -prices[index] +  dp[index+1][false];
                    int skipkaro = dp[index+1][true];
                    profit = max(buykaro, skipkaro);
                }else{
                    int sellkaro = prices[index]  - fee + dp[index+1][true];
                    int skipkaro = dp[index+1][false];
                    profit = max(sellkaro, skipkaro);
                }
                dp[index][buy] = profit;
            }   
        }
        return dp[0][true];
    }

    // 4 Space Optimization
    int SpaceOptimization(vector<int>& prices, int fee){
        int n = prices.size();
        vector<int> curr(2, 0), next(2, 0);

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;
                if(buy){
                    int buykaro = -prices[index] +  next[false];
                    int skipkaro = next[true];
                    profit = max(buykaro, skipkaro);
                }else{
                    int sellkaro = prices[index] - fee + next[true];
                    int skipkaro = next[false];
                    profit = max(sellkaro, skipkaro);
                }
                curr[buy] = profit;
            }
            next = curr;   
        }
        return curr[true];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        // 1 Recursion
        // return Recursion(prices, 0, true, fee);

        // 2 Recursion With Memoization
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return Memoization(prices, 0, true, dp, fee);

        // 3 Tabulation
        // return Tabulation(prices, fee);

        // 4 Space Optimization
        return SpaceOptimization(prices, fee);

    }
};