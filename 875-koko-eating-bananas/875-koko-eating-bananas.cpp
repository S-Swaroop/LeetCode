class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto possible = [&](int k)->bool{
            int time = 0 ; 
            for(int &i : piles){
                time += (i + k - 1) / k ; 
            }
            if(time <= h)   return true ; 
            return false ;
        };
        long long l = 0 , r = 1e10 ;
        int ans = 0 ; 
        while(r - l > 1){
            int m = l + (r - l) / 2 ; 
            if(possible(m)){
                r = m ;
                ans = m ;
            }else{
                l = m ;
            }
        }
        // if(possible(ans - 1))   ans-- ;
        return ans ; 
    }
};