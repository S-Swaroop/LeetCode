class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> s ; 
        for (int &i : nums) {
            s.insert(i) ; 
            if (s.size() > k) {
                s.erase(s.begin()) ;
            }
        }
        return *s.begin() ;
    }
};