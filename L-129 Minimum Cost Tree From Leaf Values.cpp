class Solution {
public:
    // 1 Recursion
    int Recursion(vector<int>& arr,  map<pair<int,int>, int>& maxi, int left, int right){
        if(left == right)
            return 0;
        
        int ans = INT_MAX;
        for(int i=left; i<right; i++){
            ans = min(ans, maxi[{left,i}] * maxi[{i+1, right}] + Recursion(arr, maxi, left, i) + Recursion(arr, maxi, i+1, right));
        }
        return ans;
    }

    // 2 Recursion With Memoization
    int Memoization(vector<int>& arr,  map<pair<int,int>, int>& maxi, int left, int right, vector<vector<int>>& dp){
        if(left == right)
            return 0;
        
        if(dp[left][right] != -1)
            return dp[left][right];

        int ans = INT_MAX;
        for(int i=left; i<right; i++){
            ans = min(ans, maxi[{left,i}] * maxi[{i+1, right}] + Memoization(arr, maxi, left, i, dp) + Memoization(arr, maxi, i+1, right, dp));
        }
        return dp[left][right] = ans;
    }

    // 3 Tabulation
    int Tabulation(vector<int>& arr, map<pair<int,int>, int>& maxi){
        int n = arr.size();
        vector<vector<int>> dp(n+2, vector<int>(n+1, 0));
        
        for(int left=n-1; left>=0; left--){
            for(int right=left; right<n; right++){
                if(left == right) // base condition
                    continue;

                int ans = INT_MAX;
                for(int i=left; i<right; i++){
                    ans = min(ans, maxi[{left,i}] * maxi[{i+1, right}] + dp[left][i] + dp[i+1][right]);
                }
                dp[left][right] = ans;

            }
        }
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>, int> maxi;
        int n = arr.size();
        for(int i=0; i<n; i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1; j<n; j++){
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }

        // 1 Recursion
        // return Recursion(arr, maxi, 0, n-1);

        // 2 Recursion With Memoization
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return Memoization(arr, maxi, 0, n-1, dp);

        // 3 Tabulation
        return Tabulation(arr, maxi);
    }
};