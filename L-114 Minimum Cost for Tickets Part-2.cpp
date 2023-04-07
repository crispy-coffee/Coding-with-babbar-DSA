int SpaceOptimization(vector<int>& days, vector<int>& cost){
    int ans = 0;
    queue<pair<int,int>> month;
    queue<pair<int,int>> week;
    for(auto day:days){
        // step 1: Removing invalid days from month
        while(!month.empty() and month.front().first+30 <= day)
            month.pop();
        
        while(!week.empty() and week.front().first+7 <= day)
            week.pop();
        
        // step 2: push pair
        month.push({day, ans+cost[2]});
        week.push({day, ans+cost[1]});

        // check minimum Cost
        ans = min({ans + cost[0], week.front().second, month.front().second});
    }
    
    return ans;
}

int mincostTickets(vector<int>& day, vector<int>& cost) {

    // 4 Space Optimization
    return SpaceOptimization(day, cost);

}