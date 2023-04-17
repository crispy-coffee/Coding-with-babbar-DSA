class Solution {
public:
    void nextsmallelement(vector<int>& heights, vector<int>& next, int n){
        stack<int> s;
        s.push(n);
        for(int i=n-1; i>=0; i--){
            while(s.top() != n and heights[s.top()] >= heights[i]){
                s.pop();
            }
            next[i] = s.top();
            s.push(i);
        }
    }

    void prevsmallelement(vector<int>& heights, vector<int>& prev, int n){
        stack<int> s;
        s.push(n);
        for(int i=0; i<n; i++){
            while(s.top() != n and heights[s.top()] >= heights[i]){
                s.pop();
            }
            prev[i] = s.top();
            s.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights){
        int n = heights.size();
        vector<int> next(n), prev(n);
        nextsmallelement(heights, next, n);
        prevsmallelement(heights, prev, n);

        int area = 0;

        for(int i=0; i<n; i++){
            int height = heights[i];
            int breadth = next[i] - prev[i] - 1;

            int currarea = height * breadth;
            area = max(area, currarea);
        }

        return area;
    }
    
};