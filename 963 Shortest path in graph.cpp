#include <bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	
	unordered_map<int,vector<int>> adj;

	for(auto i:edges){
		adj[i.first].push_back(i.second);
		adj[i.second].push_back(i.first);
	}

	vector<bool> visited(n+1,false);
	vector<int> parent(n+1);
	queue<int> q;
	q.push(s);
	parent[s] = -1;
	visited[s] = true;

	while(!q.empty()){
		int node = q.front();
		q.pop();

		for (auto child : adj[node]){
			if(visited[child] == false){
				visited[child] = true;
				q.push(child);
				parent[child] = node;
			} 
		}
	}
	


	vector<int> v;
	int ans = t;
	v.push_back(ans);
	while(ans != s){
		ans = parent[ans];
		v.push_back(ans);
	}
	reverse(begin(v),end(v));


	return v;
	
}
