class Solution{
public:
    
    int minimumDays(int S, int N, int M){
        int Lmao_Dead = -1;
        int foodRequire = S*M;
        int sunday = S/7;
        int CanBuyDays = S-sunday;
        
        int NeedToBuyDays = 0;
        
        if(foodRequire % N == 0){
            NeedToBuyDays = foodRequire / N;
        }else{
            NeedToBuyDays = foodRequire / N + 1;
        }
        
        if(NeedToBuyDays > CanBuyDays){
            return Lmao_Dead;
        }
        return NeedToBuyDays;
        
    }
};