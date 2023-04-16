class Solution {
public:
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
    int Tabulation(vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=2; limit++){
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
        return dp[0][true][2];
    }

    // 4 Space Optimization
    int SpaceOptimization(vector<int>& prices){
        int n = prices.size();
        
        vector<vector<int>> curr(2, vector<int>(3,0)), next(2, vector<int>(3,0));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=2; limit++){
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
        return curr[true][2];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 1 Recursion
        // return Recursion(prices, 0, true, 2);

        // 2 Recursion With Memoization
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        // return Memoization(prices, 0, true, dp, 2);

        // 3 Tabulation
        // return Tabulation(prices);

        // 4 Space Optimization
        return SpaceOptimization(prices);
    }
};