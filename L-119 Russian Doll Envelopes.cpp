class Solution {
public:
    class cmp {
    public:
        bool operator()(vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        }
    };

    int binarysearch(vector<vector<int>>& envelopes){
        sort(envelopes.begin(), envelopes.end(), cmp());
        int size = envelopes.size();
        vector<int> v;
        v.push_back(envelopes[0][1]);

        for(int i=1; i<size; i++){
            if(v.back() < envelopes[i][1]){
                v.push_back(envelopes[i][1]);
            }else{
                int index = lower_bound(v.begin(), v.end(), envelopes[i][1]) - v.begin();
                v[index] = envelopes[i][1];
            }
        }

        return v.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        return binarysearch(envelopes);
    }
};