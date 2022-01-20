class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //utility function to check if the we can eat all the bananas at rate k in h hours
        auto possible = [&](int k)->bool{ 
            int time_taken = 0 ; 
            for(int &i : piles){
                time_taken += (i + k - 1) / k ; 
            }
            return (time_taken <= h) ; 
        };
        long long low = 0 , high = 1e10 ;
        int ans = 0 ; 
        while(high - low > 1){
            int mid = low + ((high - low) >> 1) ; 
            if(possible(mid)){
                high = mid ;
                ans = mid ;
            }else{
                low = mid ;
            }
        }
        return ans ; 
    }
};