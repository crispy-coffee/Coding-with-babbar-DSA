#define ll long long 
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        priority_queue<ll, vector<ll>, greater<ll>> pq(arr, arr+n);
        
        ll cost = 0;
        while(pq.size()>1){
            ll first = pq.top();
            pq.pop();
            
            ll second = pq.top();
            pq.pop();
            
            ll merge = first + second;
            cost += merge;
            pq.push(merge);
        }
        
        return cost;
    }
};