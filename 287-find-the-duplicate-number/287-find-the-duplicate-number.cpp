class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() ;
        auto count = [&] (int num) {
            int res = 0 ;
            for (int &i : nums) {
                if (i <= num) {
                    res++ ;
                }
            }
            return res ;
        };
        int ans = -1 ;
        int l = 1 , r = n ; 
        while (r >= l) {
            int m = l + (r - l) / 2 ; 
            if (count(m) > m) {
                ans = m ;
                r = m - 1 ;
            } else {
                l = m + 1 ;
            }
        }
        return ans ; 
    }
};