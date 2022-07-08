class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0 , high = nums.size() - 1 ; 
        while (low < high) {
            int mid = (low + high) >> 1 ; 
            if (nums[mid] > nums.back()) {
                low = mid + 1 ; 
            } else {
                high = mid ;
            }
        }
        return nums[low] ;
    }
};