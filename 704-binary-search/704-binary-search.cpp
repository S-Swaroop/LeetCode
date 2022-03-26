class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = -1 , r = nums.size() ;
        while (r - l > 1) {
            int m = l + (r - l) / 2 ;
            if (nums[m] == target) {
                return m ;
            } else if (nums[m] < target) {
                l = m ; 
            } else {
                r = m ;
            }
        }
        return -1 ;
    }
};