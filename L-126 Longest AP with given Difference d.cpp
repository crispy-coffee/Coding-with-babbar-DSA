class Solution {
public:

    // 1 Recursion
    int Recursion(vector<int>& arr, int difference, int index){
        if(index==arr.size())
            return 0;
        
        int ans = 1;
        for(int j=index-1; j>=0; j--){
            if(arr[index]-arr[j] == difference){
                ans = max(ans, 1+Recursion(arr, difference, j));
            }
        }
        return ans;
    }

    // 2 Recursion With Memoization
    int RecursionWithMemoization(vector<int>& arr, int difference, int index, unordered_map<int,int>& dp){
        if(index==arr.size())
            return 0;
        
        if(dp.count(index))
            return dp[index];

        int ans = 1;
        for(int j=index-1; j>=0; j--){
            if(arr[index]-arr[j] == difference){
                ans = max(ans, 1+RecursionWithMemoization(arr, difference, j, dp));
            }
        }
        return dp[index] = ans;
    }

    // 3 Tabulation
    int Tabulation(vector<int>& arr, int difference){
        int n = arr.size();
        unordered_map<int,int> dp;
        int ans = 1;
        for(int i=0; i<n; i++){
            int exist = arr[i]-difference;
            if(dp.count(exist)){
                dp[arr[i]] = 1+dp[exist];
            }else{
                dp[arr[i]] = 1;
            }
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }

    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        int ans = 1;

        // 1 Recursion (TLE)
        for(int i=0; i<n; i++){
            ans = max(ans, Recursion(arr, difference, i));
        }
        
        // 2 Recursion With Memoization (TLE)
        // unordered_map<int,int> dp;
        // for(int i=0; i<n; i++){
        //     ans = max(ans, RecursionWithMemoization(arr, difference, i, dp));
        // }


        // 3 Tabulation (Accepted)
        // ans = Tabulation(arr, difference);
        return ans;
    }
};