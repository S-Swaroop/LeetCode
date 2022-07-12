class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0 , n = nums.size() ; i < n ; i++) {
            nums[abs(nums[i]) - 1] *= -1 ; 
            if (nums[abs(nums[i]) - 1] > 0) {
                return abs(nums[i]) ;
            }
        }
        return 0 ;
    }
};