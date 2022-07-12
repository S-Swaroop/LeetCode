class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() ;
        auto count = [&] (int x) -> bool {
            int res = 0 ; 
            for (int &i : nums) {
                res += i <= x ; 
            }
            return res > x ; 
        };
        int low = 0 , high = n + 1 ; 
        while (high - low > 1) {
            int mid = low + ((high - low) >> 1) ;
            if (count (mid)) {
                high = mid ; 
            } else {
                low = mid ;
            }
        }
        return high ;
    }
};