class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0 ;
        }
        set<int> present ; 
        for (int &i : nums) {
            present.insert(i) ; 
        }
        int len = 0 , last = -1e5 , ans = 0 ; 
        for (auto i : present) {
            if (i - last <= 1) {
                len++ ; 
            } else {
                len = 1 ; 
            }
            ans = max(ans , len) ; 
            last = i ;
        }
        return ans ;
    }
};