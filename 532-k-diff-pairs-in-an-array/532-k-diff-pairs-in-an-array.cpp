class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map <int , int> f ;
        for (int i : nums) {
            f[i]++ ; 
        }
        int ans = 0 ; 
        for (auto i : f) {
            if (k > 0 && f.find(i.first + k) != f.end())   ans++ ;
            if (k == 0 && f[i.first] > 1) {
                ans++ ;
            }
        }
        return ans ;
    }
};