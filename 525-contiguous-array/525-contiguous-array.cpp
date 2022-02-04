class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size() ; 
        unordered_map<int , int> f ; 
        f[0] = -1 ; 
        int count = 0 , max_len = 0 ; 
        for (int i = 0 ; i < n ; i++) {
            count = count + (nums[i] == 1 ? 1 : -1) ;
            if (f.find(count) != f.end()) {
                max_len = max(max_len , i - f[count]) ; 
            } else {
                f[count] = i ; 
            }
        }
        return max_len ; 
    }
};