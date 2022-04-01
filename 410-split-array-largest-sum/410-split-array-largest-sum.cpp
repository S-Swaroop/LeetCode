class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size() ; 
        int low = *max_element(nums.begin() , nums.end()) , high = accumulate(nums.begin() , nums.end() , 0) ; 
        int ans ;
        auto possible = [&] (int sum) {
            int curr_sum = 0 , splits = 0 ;
            for (int i = 0 ; i < n ; i++) {
                if (curr_sum + nums[i] > sum) {
                    splits++ ;
                    curr_sum = nums[i] ;
                } else {
                    curr_sum += nums[i] ;
                }
            }
            return splits + 1 <= m ;
        } ;
        while (high >= low) {
            int mid = low + ((high - low) / 2) ;
            if (possible (mid)) {
                ans = mid ; 
                high = mid - 1 ; 
            } else {
                low = mid + 1 ;
            }
        }
        return ans ; 
    }
};