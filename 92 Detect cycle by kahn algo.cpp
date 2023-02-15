#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
  unordered_map<int,vector<int>> adj;

  vector<int> indegree(v);
  for(auto i:edges){
      adj[i[0]].push_back(i[1]);
      indegree[i[1]]++;

  }

  queue<int> q;
  for(int i=0; i<v; i++){
      if(indegree[i] == 0)
          q.push(i);
  }

  int ans;

  while(!q.empty()){
      int node = q.front();


      for(auto neighbour : adj[node]){
          indegree[neighbour]--;
          if(indegree[neighbour] == 0){
              q.push(neighbour);
          }
      }
      
      q.pop();

     ans++;

  }

  if(ans == v) return true;
  return false;
  
}
