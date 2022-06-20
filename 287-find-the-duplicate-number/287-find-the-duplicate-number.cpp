class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1 ; 
        auto count = [&] (int num) {
            int res = 0 ;
            for (int &i : nums) {
                if (i <= num) {
                    res++ ;
                }
            }
            return res ;
        } ;
        int l = 1 , r = n ; 
        while (r - l > 1) {
            int m = l + (r - l) / 2 ;
            if (count(m) > m) {
                r = m ; 
            } else {
                l = m ;
            }
        }
        return count(l) > l ? l : r ; 
    }
};