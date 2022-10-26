class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size() ;
        unordered_map<int , int> f ;
        f[0] = 0 ;
        int sum = 0 ; 
        for (int i = 0 ; i < n ; i++) {
            sum += nums[i] ; 
            if (!f.count(sum % k)) {
                f[sum % k] = i + 1 ;
            } else if (f[sum % k] < i) {
                return true ;
            }
        }
        return false ;
    }
};