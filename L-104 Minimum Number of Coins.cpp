#include <bits/stdc++.h> 

// 1 Recursion
int recursion(vector<int>& num, int x){
    if(x == 0)
        return 0;

    if(x<0)
        return INT_MAX;
    

    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++) {
        int ans = recursion(num, x-num[i]);

        if(ans != INT_MAX){
            mini = min(mini, ans+1);
        }
    }

   return mini;
}

// 2 Recursion with memoizatoin
int recursion_with_memo(vector<int>&num ,int x, vector<int>& dp){

    if(x == 0)
        return 0;

    if(x<0)
        return INT_MAX;
    

    if(dp[x] != -1){
        return dp[x];
    }

    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++) {
        int ans = recursion_with_memo(num, x-num[i]);

        if(ans != INT_MAX){
            mini = min(mini, ans+1);
        }
    }
    
    dp[x] = mini;
    return mini;

}

int minimumElements(vector<int> &num, int x)
{   
    // 1 Recursion
    
    // int recursion_ans = recursion(num, x);
    // return recursion_ans != INT_MAX ? recursion_ans:-1;
    
    // 2 Recursion with memo
    vector<int> dp(x+1, -1);
    int memo_ans = recursion_with_memo(num, x, dp);
    return memo_ans != INT_MAX ? memo_ans:-1;

    //30-march-2023
    // video smjh hi nhi aayi mere isiliye aage ki approach nhi kri


}