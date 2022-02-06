class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0 ; 
        for (int &num : nums) {
            if (i < 2 || nums[i - 2] != num) {
                nums[i++] = num ; 
            }
        }
        return i ; 
    }
};
/*
    1 2 2 2 2 3 
    
*/