class Solution 
{
    public:
    static bool cmp(Job a, Job b){
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n){
        sort(arr, arr+n, cmp);
        
        int maxideadline = INT_MIN;
        for(int i=0; i<n; i++){
            maxideadline = max(maxideadline, arr[i].dead);
        }
        vector<int> schedule(maxideadline+1, -1);
        
        int maxprofit = 0;
        int count = 0;
        for(int i=0; i<n ;i++){
            int currprofit = arr[i].profit;
            int currjobid = arr[i].id;
            int currdeadline = arr[i].dead;
            
            for(int k=currdeadline; k>0; k--){
                if(schedule[k] == -1){
                    schedule[k] = currjobid;
                    maxprofit += currprofit;
                    count++;
                    break;
                }
            }
        }
        
        return {count ,maxprofit};
    } 
};