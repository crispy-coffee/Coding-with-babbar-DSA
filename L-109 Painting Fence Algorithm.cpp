#include <bits/stdc++.h> 
#define MOD 1000000007
// 1 Recursion
int Recursion(int n, int k){
    
    if(n == 1)
        return k;

    if(n == 2){
        return (k + (k*(k-1)))%MOD;
    }

    int solve = (Recursion(n-2, k) * (k-1) + Recursion(n-1, k) * (k-1)) % MOD;
    return solve;
}

// 2 Recursion With Memoization
int RecursionWithMemoization(int n, int k, vector<int>& dp){

    if(n == 1)
        return k;

    if(n == 2){
        return (k + (k*1LL*(k-1)))%MOD;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = (RecursionWithMemoization(n-2, k, dp) *1LL* (k-1) + RecursionWithMemoization(n-1, k, dp) *1LL* (k-1)) % MOD;
    return dp[n];

}
// 3 Tabulation
int Tabulation(int n, int k){
    vector<int> dp(n+1, 0);

    dp[1] = k;
    dp[2] = (k + (k*1LL*(k-1)))%MOD;
    
    for(int i=3; i<=n; i++){
        dp[i] = ((dp[i-2] *1LL* (k-1)) + (dp[i-1] *1LL* (k-1))) % MOD;
    }

    return dp[n];

}

// 4 Space Optimization
int SpaceOptimizatoin(int n, int k){

    int prev2 = k;
    int prev1 = (k + (k*1LL*(k-1)))%MOD;
    
    for(int i=3; i<=n; i++){
        int ans = ((prev2 *1LL* (k-1)) + (prev1 *1LL* (k-1))) % MOD;
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int numberOfWays(int n, int k) {
    // 1 Recursion
    // return Recursion(n, k);

    // 2 Recursion With Memoization
    // vector<int> dp(n+1, -1);
    // return RecursionWithMemoization(n, k, dp);

    // 3 Tabulation
    // return Tabulation(n, k);

    // 4 Space Optimization
    return SpaceOptimizatoin(n, k);

}
