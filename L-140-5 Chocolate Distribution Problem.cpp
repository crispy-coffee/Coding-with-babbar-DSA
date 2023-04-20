class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(begin(a), end(a));
        long long i=0, j=m-1;
        long long mini = INT_MAX;
        
        for(j; j<n; i++,j++){
            mini = min(mini, a[j]-a[i]);
        }
        
        return mini;
    }   
};
