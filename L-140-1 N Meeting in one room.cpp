class Solution
{
    public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second<b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> meet;
        for(int i=0; i<n; i++){
            meet.push_back({start[i], end[i]});
        }
        
        sort(meet.begin(), meet.end(), cmp);
        int meeting = 1;
        int prev = meet[0].second;
        for(int i=1; i<n; i++){
            if(prev < meet[i].first){
                meeting++;
                prev = meet[i].second;
            }
        }
        
        return meeting;
    }
};