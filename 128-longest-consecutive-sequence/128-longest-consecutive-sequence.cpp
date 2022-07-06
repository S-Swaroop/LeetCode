class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin() , nums.end()) ;
        int longestStreak = 0 ; 
        for (int i : s) {
            if (s.find(i - 1) == s.end()) {
                int currNum = i ; 
                int currentStreak = 1 ; 
                while (s.find(currNum + 1) != s.end()) {
                    currNum++ ; 
                    currentStreak++ ;
                }
                longestStreak = max(longestStreak , currentStreak) ; 
            }
        }
        return longestStreak ;
    }
};