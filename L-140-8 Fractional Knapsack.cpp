class Solution
{
    public:
    static bool cmp(pair<double, Item>& a, pair<double, Item>& b){
        return a.first > b.first;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double, Item>> v;
        for(int i=0; i<n; i++){
            double PerUnitValue = (double)arr[i].value / arr[i].weight;
            v.push_back({PerUnitValue, arr[i]});
        }
        
        sort(begin(v), end(v), cmp);
        
        double maxi = 0;
        for(int i=0; i<n; i++){
            if(v[i].second.weight < W){
                maxi += v[i].second.value;
                W -= v[i].second.weight;
            }else{
                maxi += v[i].first * W;
                W = 0;
                break;
            }
        }
        
        return maxi;
    }
        
};