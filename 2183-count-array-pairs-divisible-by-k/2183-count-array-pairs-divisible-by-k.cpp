class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long ans = 0ll ;
        unordered_map<int , int> f ; 
        for (int &i : nums) {
            long long gcd = __gcd(i , k) ;
            for (auto &j : f) {
                if ((j.first * gcd) % k == 0) {
                    ans += j.second ;
                }
            }
            f[gcd]++ ;
        }
        return ans ;
    }
};