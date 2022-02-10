class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> f ;
        f[0] = 1 ;
        int sum = 0 , count = 0 , n = nums.size() ; 
        for (int i = 0 ; i < n ; i++) {
            sum += nums[i] ; 
            if (f.find(sum - k) != f.end()) {
                count += f[sum - k] ;
            }
            f[sum]++ ;
        }
        return count ; 
    }
};