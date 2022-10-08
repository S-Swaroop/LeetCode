class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end()) ;
        int n = nums.size() ; 
        int first = 0 , second = first + 1 , third = n - 1 ;
        int best = nums[first] + nums[second] + nums[third] ;
        while (first < n - 2) {
            while (third > second) {
                int curr_sum = nums[first] + nums[second] + nums[third] ;
                if (abs(target - curr_sum) == abs(target - best)) {
                    best = max(best , curr_sum) ;
                } else if (abs(target - curr_sum) < abs(target - best)) {
                    best = curr_sum ;
                }
                if (curr_sum < target) {
                    second++ ;
                } else if (curr_sum > target) {
                    third-- ;
                } else {
                    break ;
                }
            }
            first++ ; 
            second = first + 1 ; 
            third = n - 1 ;
        }
        return best ;
    }
};