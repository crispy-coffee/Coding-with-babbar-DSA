class Solution
{
    public:
    string reverseWords(string S){
        
        string ans = "";
        int size = S.size();
        int j = size-1;
        for(int i=size-1; i>=0; i--){
            if(S[i] == '.'){
                ans += S.substr(i+1, j-i);
                ans += '.';
                j = i-1;
            }
        }
        
        ans += S.substr(0,j+1);
        return ans;
       
    } 
};