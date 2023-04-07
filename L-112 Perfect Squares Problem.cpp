class Solution {
public:
   
    // 1 Recursion
    int Recursion(int n){
        if(n == 0)
            return 0;
        int ans = n;
        for(int i=1; i*i<=n; i++){
            ans = min(ans, 1+Recursion(n-i*i));
        }   

        return ans;
    }

    // 2 Recursion With Memoizatoin
    int RecursionWithMemoization(int n, vector<int>& dp){
        if(n == 0)
            return 0;
        if(dp[n] != -1)
            return dp[n];

        int ans = n;
        for(int i=1; i*i<=n; i++){
            ans = min(ans, 1+RecursionWithMemoization(n-i*i, dp));
        }
        return dp[n] = ans;
    }

    // 3 Tabulation
    int Tabulation(int n){
        vector<unsigned long long int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j*j<=i; j++){ 
            //In love babbar video he run the second loop till n but instead of n we need to run till i 
            //because in recurstion we are decreasing the n's value it's not fixed so 
            //how can we run the loop till n?
                if(i-j*j>=0)
                dp[i] = min(dp[i],1+dp[i-j*j]);
            }
        }
        return (int)dp[n];
    }

    int numSquares(int n) {
        // 1 Recursion
        // return Recursion(n);

        // 2 Recursion With Memoization
        // vector<int> dp(n+1, -1);
        // return RecursionWithMemoization(n, dp);

        // 3 Tabulation
        return Tabulation(n);
    }
};