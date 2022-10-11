class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int smallest = INT_MAX , second_smallest = INT_MAX ; 
        for (int i = 0 ; i < (int)nums.size() ; i++) {
            if (nums[i] > second_smallest) {
                return true ;
            } else if (nums[i] > smallest) { 
                second_smallest = nums[i] ;
            } else if (nums[i] < smallest) {
                // second_smallest = smallest ;
                smallest = nums[i] ; 
            }
        }
        return false ;
    }
};