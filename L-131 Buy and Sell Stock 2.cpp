class Solution {
public:
    // 1 Recursion
    int Recursion(vector<int>& prices, int index, bool buy){
        if(index == prices.size())
            return 0;

        //Buy = True means we can buy
        int profit = 0;
        if(buy){
            int buykaro = -prices[index] +  Recursion(prices, index+1, false);
            int skipkaro =  Recursion(prices, index+1, true);
            profit = max(buykaro, skipkaro);
        }else{
            int sellkaro = prices[index] +  Recursion(prices, index+1, true);
            int skipkaro =  Recursion(prices, index+1, false);
            profit = max(sellkaro, skipkaro);
        }

        return profit;
    }

    // 2 Recursion With Memoization
    int Memoization(vector<int>& prices, int index, bool buy, vector<vector<int>>& dp){
        if(index == prices.size())
            return 0;

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        //Buy = True means we can buy
        int profit = 0;
        if(buy){
            int buykaro = -prices[index] +  Memoization(prices, index+1, false, dp);
            int skipkaro =  Memoization(prices, index+1, true, dp);
            profit = max(buykaro, skipkaro);
        }else{
            int sellkaro = prices[index] +  Memoization(prices, index+1, true, dp);
            int skipkaro =  Memoization(prices, index+1, false, dp);
            profit = max(sellkaro, skipkaro);
        }

        return dp[index][buy] = profit;
    }

    // 3 Tabulation
    int Tabulation(vector<int>& prices){
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
                    int sellkaro = prices[index] + dp[index+1][true];
                    int skipkaro = dp[index+1][false];
                    profit = max(sellkaro, skipkaro);
                }
                dp[index][buy] = profit;
            }   
        }
        return dp[0][true];
    }

    // 4 Space Optimization
    int SpaceOptimization(vector<int>& prices){
        int n = prices.size();
        // vector<vector<int>> dp(n+2, vector<int>(2, 0));
        vector<int> curr(2, 0), next(2, 0);

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;
                if(buy){
                    int buykaro = -prices[index] +  next[false];
                    int skipkaro = next[true];
                    profit = max(buykaro, skipkaro);
                }else{
                    int sellkaro = prices[index] + next[true];
                    int skipkaro = next[false];
                    profit = max(sellkaro, skipkaro);
                }
                curr[buy] = profit;
            }
            next = curr;   
        }
        return curr[true];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 1 Recursion
        // return Recursion(prices, 0, true);

        // 2 Recursion With Memoization
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return Memoization(prices, 0, true, dp);

        // 3 Tabulation
        // return Tabulation(prices);

        // 4 Space Optimization
        return SpaceOptimization(prices);

        // Khatarnak approach 
        /*
        int profit = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i-1]<prices[i])
                profit+= prices[i]-prices[i-1];
        }
        return profit;
        */
    }
};