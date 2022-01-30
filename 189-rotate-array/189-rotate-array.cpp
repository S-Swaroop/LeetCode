class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k >= (int)nums.size())    k = k % (int)nums.size() ; 
        reverse(0 , nums.size() - k , nums) ;
        reverse(nums.size() - k , nums.size() , nums) ;
        reverse(0 , nums.size() , nums) ;
    }
private: 
    void reverse(int start , int end , vector<int> &nums) {
        int l = start , r = end - 1 ; 
        while (l < r) {
            swap(nums[l] , nums[r]) ; 
            l++ ; r-- ; 
        }
    }
};