class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> pref(n , 0) , suf(n , 0) , lis ;
        for(int i = 0 ; i < n - 1 ; i++){
            int val = nums[i] ; 
            auto it = lower_bound(lis.begin() , lis.end() , val) ; 
            pref[i] = it - lis.begin() ; 
            if(it != lis.end()) *it = nums[i] ; 
            else    lis.push_back(nums[i]) ; 
        }
        lis.clear() ; 
        for(int i = n - 1 ; i > 0 ; i--){
            int val = nums[i] ; 
            auto it = lower_bound(lis.begin() , lis.end() , val) ; 
            suf[i] = it - lis.begin() ; 
            if(it != lis.end()) *it = nums[i] ; 
            else    lis.push_back(nums[i]) ; 
        }
        int ans = n ; 
        for(int i = 1 ; i < n - 1 ; i++){
            if(pref[i] && suf[i])  ans = min(ans , n - (pref[i] + suf[i] + 1)) ;
        }
        return ans ;
    }
};