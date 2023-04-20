class Solution
{
    public:

    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second<b.second;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> acty;
        for(int i=0; i<n; i++){
            acty.push_back({start[i], end[i]});
        }
        
        sort(acty.begin(), acty.end(), cmp);
        int activity = 1;
        int prev = acty[0].second;
        for(int i=1; i<n; i++){
            if(prev < acty[i].first){
                activity++;
                prev = acty[i].second;
            }
        }
        
        return activity;
    }
};