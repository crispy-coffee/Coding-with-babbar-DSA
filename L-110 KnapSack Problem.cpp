#include <bits/stdc++.h> 

// 1 Recursion
int Recursion(vector<int>& weight, vector<int> &value, int index, int capacity){
	
	if(index == 0){
		if(weight[0] <= capacity){
			return value[0];
		}else{
			return 0;
		}
	}

	int include = 0;
	if(weight[index] <= capacity)
		include = value[index] + Recursion(weight, value, index-1, capacity-weight[index]);

	int exclude = 0 + Recursion(weight, value, index-1, capacity);
	
	return max(exclude, include);

}



// 2 Recursion With Memoization
int RecursionWithMemoization(vector<int>& weight, vector<int> &value, int index, int capacity, vector<vector<int>>& dp){
	
	if(index == 0){
		if(weight[0] <= capacity){
			return value[0];
		}else{
			return 0;
		}
	}

	if(dp[index][capacity] != -1){
		return dp[index][capacity];
	}

	int include = 0;
	if(weight[index] <= capacity)
		include = value[index] + RecursionWithMemoization(weight, value, index-1, capacity-weight[index], dp);

	int exclude = 0 + RecursionWithMemoization(weight, value, index-1, capacity, dp);
	
	return dp[index][capacity] = max(exclude, include);

}

// 3 Tabulation
int Tabulation(vector<int>& weight, vector<int> &value, int index, int capacity){
	vector<vector<int>> dp(index,vector<int>(capacity+1, 0));

	for(int i= weight[0]; i<=capacity; i++){
		if(weight[0] <= capacity){
			dp[0][i] = value[0];
		}else{
			dp[0][i] = 0;
		}
	}
		
	for(int i=1; i<index; i++)	{
		for(int w=0; w<=capacity; w++){
			int include = 0;
			if(weight[i] <= w)
				include = value[i] + dp[i-1][w-weight[i]];

			int exclude = 0 + dp[i-1][w];
			
			dp[i][w] = max(exclude, include);
		}
	}
	
	return dp[index-1][capacity];

}

// 4 Space Optimization
int SpaceOptimization(vector<int>& weight, vector<int> &value, int index, int capacity){
	vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);

	for(int i= weight[0]; i<=capacity; i++){
		if(weight[0] <= capacity){
			prev[i] = value[0];
		}else{
			prev[i] = 0;
		}
	}
		
	for(int i=1; i<index; i++)	{
		for(int w=0; w<=capacity; w++){
			int include = 0;
			if(weight[i] <= w)
				include = value[i] + prev[w-weight[i]];

			int exclude = 0 + prev[w];
			
			curr[w] = max(exclude, include);
		}
		prev = curr;
	}
	
	return prev[capacity];

}

// 5 Space Optimization
int SpaceOptimization2(vector<int>& weight, vector<int> &value, int index, int capacity){
	vector<int> curr(capacity+1, 0);

	for(int i= weight[0]; i<=capacity; i++){
		if(weight[0] <= capacity){
			curr[i] = value[0];
		}else{
			curr[i] = 0;
		}
	}
		
	for(int i=1; i<index; i++)	{
		for(int w=capacity; w>=0; w--){ // curr[w]-> is depend on either left side of prev[w] or prev[w] 
                                        // so just run the loop inversely no problem will occurs
			int include = 0;
			if(weight[i] <= w)
				include = value[i] + curr[w-weight[i]];

			int exclude = 0 + curr[w];
			
			curr[w] = max(exclude, include);
		}
	}
	
	return curr[capacity];

}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	//1 Recursion
	// return Recursion(weight, value, n-1, maxWeight);

	// 2 Recursion with Memoization
	// vector<vector<int>> dp(n,vector<int>(maxWeight+1, -1));
	// return RecursionWithMemoization(weight, value, n-1, maxWeight, dp);

	// 3 Tabulation
	// return Tabulation(weight, value, n, maxWeight);

	// 4 Space Optimization
	// return SpaceOptimization(weight, value, n, maxWeight);

	// 5 Space Optimization
	return SpaceOptimization2(weight, value, n, maxWeight);

}