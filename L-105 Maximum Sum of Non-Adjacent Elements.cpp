#include <bits/stdc++.h> 

// 1 Recursion but bottom up approach
int recursionbottonup(vector<int> &nums, int index){
    if(index >= nums.size()){
        return 0;
    }

    if(index == nums.size()-1){
        return nums[index];
    }

    int include = recursionbottonup(nums, index+2) + nums[index];
    int exclude = recursionbottonup(nums, index+1);

    return max(include, exclude);
}


// 2 Recursion with top down approach
int recursiontopdown(vector<int>& nums, int index){

    if(index < 0){
        return 0;
    }

    if(index == 0){
        return nums[0];
    }


    int include = recursiontopdown(nums, index-2) + nums[index];
    int exclude = recursiontopdown(nums, index-1);

    return max(include,exclude);

}


// 3 Recursion with memo but top-down approach
int memotopdown(vector<int>& nums, int index, vector<int>& dp){

    if(index < 0){
        return 0;
    }

    if(index == 0){
        return nums[0];
    }

    if(dp[index] != -1){
        return dp[index];
    }

    int include = memotopdown(nums, index-2, dp) + nums[index];
    int exclude = memotopdown(nums, index-1, dp);

    dp[index] = max(include,exclude);
    return dp[index];

}


// 4 Recursion with memo but bottom-up approach
int memobottomup(vector<int>& nums, int index, vector<int>& dp){

    if(index>=nums.size()){
        return 0;
    }

    if(index == nums.size()-1){
        return nums[index];
    }

    if(dp[index] != -1)
        return dp[index];

    int include = memobottomup(nums, index+2, dp) + nums[index];
    int exclude = memobottomup(nums, index+1, dp);

    dp[index] = max(include,exclude);
    return dp[index];

}


// 5 tabulation
int tabulation(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    
    dp[0] = nums[0];

    for(int i=1; i<n; i++){
        int include = dp[i-2] + nums[i];
        int exclude = dp[i-1];

        dp[i] = max(include,exclude);
    }

    return dp[n-1];
}


//6 spaceoptimization
int spaceoptimization(vector<int>& nums){
    int prev1 = 0;
    int prev2 = nums[0];
    int n = nums.size(), ans=nums[0];
    for(int i=1; i<n ;i++){
        int include = prev1 + nums[i];
        int exclude = prev2;

        ans = max(include,exclude);
        prev1 = prev2;
        prev2 = ans;
    }

    return ans;
}


int maximumNonAdjacentSum(vector<int> &nums){

    int n = nums.size();

    //1 recursion with bottom-up approach
    // return recursionbottonup(nums, 0);
    

    //2 recurion with top-down approach
    // return recursiontopdown(nums, n-1);


    //3 recursion with memo with top-down approach
    // vector<int> dp(n, -1);   
    // return memotopdown(nums, n-1, dp);
    

    //4 recursion with memo with bottom-up approach
    // vector<int> dp(n, -1);
    // return memobottomup(nums, 0, dp);


    //5 tabulation
    // return tabulation(nums);
    
    //6 Space Optimization
    return spaceoptimization(nums);

}














