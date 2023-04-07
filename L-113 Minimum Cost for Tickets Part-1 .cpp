class Solution {
public:

    // 1 Recursion
    int Recursion(vector<int>& day, vector<int>& cost, int index){
        if(index>= day.size()){
            return 0;
        }

        int option1 = cost[0] + Recursion(day, cost, index+1);

        int i = index;
        for(i; i<day.size() && day[i]<day[index]+7; i++);

        int option2 = cost[1] + Recursion(day, cost, i);

        int k = index;
        for(k; k<day.size() && day[k]<day[index]+30; k++);

        int option3 = cost[2] + Recursion(day, cost, k);

        return min({option1, option2, option3});

    }
    
    // 2 Recursion With Memoization
    int RecursionWithMemoization(vector<int>& day, vector<int>& cost, int index, vector<int>& dp){
        if(index>= day.size()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int option1 = cost[0] + RecursionWithMemoization(day, cost, index+1, dp);

        int i ;
        for(i = index; i<day.size() && day[i]<day[index]+7; i++);

        int option2 = cost[1] + RecursionWithMemoization(day, cost, i, dp);

        int k ;
        for(k = index; k<day.size() && day[k]<day[index]+30; k++);

        int option3 = cost[2] + RecursionWithMemoization(day, cost, k, dp);

        return dp[index] = min({option1, option2, option3});

    }

    // 3 Tabulation
    int Tabulation(vector<int>& day, vector<int>& cost){
        int n = day.size();
        vector<int> dp(n+1, 0);
        dp[n] = 0;

        for(int index=n-1; index>=0; index--){
            int option1 = cost[0] + dp[index+1];

            int i ;
            for(i = index; i<n && day[i]<day[index]+7; i++);

            int option2 = cost[1] + dp[i];

            int k;
            for(k = index; k<n && day[k]<day[index]+30; k++);

            int option3 = cost[2] + dp[k];

            dp[index] = min({option1, option2, option3});
        }

        return dp[0];

    }


    int mincostTickets(vector<int>& day, vector<int>& cost) {

        // 1 Recursion
        // return Recursion(day, cost, 0) ;

        // 2 Recursion With Memoization
        // vector<int> dp(day.size()+1, -1);
        // return RecursionWithMemoization(day, cost, 0, dp);

        // 3 Tabulation
        return Tabulation(day, cost);

    }
};