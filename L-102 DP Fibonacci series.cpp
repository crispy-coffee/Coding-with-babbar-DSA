//top-down + memoization
    
int rec(vector<int> &dp, int n){
    if(n==0 || n==1) return n;

    if(dp[n] != -1) return dp[n];

    dp[n] = rec(dp, n-1) + rec(dp, n-2);
    return dp[n];
}

int fib(int n) {
    vector<int> dp(n+1, -1);
    return rec(dp, n);
}


//Bottom-up approach
int fib(int n) {
    if(n==0 || n==1) return n;
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

//Space-Optimisation
int fib(int n) {

    if(n==0) return 0;
    if(n==1) return 1;
    int first = 0;
    int second = 1;
    int third = 0 ;
    for(int i=2; i<=n; i++){
        third = first + second;
        first = second;
        second = third;
    }

    return third;
}