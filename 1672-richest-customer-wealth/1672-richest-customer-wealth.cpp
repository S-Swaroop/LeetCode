class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = 0 ;
        for (vector<int> &bank : accounts) {
            int wealth = 0 ; 
            for (int &balance : bank) {
                wealth += balance ; 
            }
            if (wealth > max_wealth) {
                max_wealth = wealth ; 
            }
        }
        return max_wealth ;
    }
};