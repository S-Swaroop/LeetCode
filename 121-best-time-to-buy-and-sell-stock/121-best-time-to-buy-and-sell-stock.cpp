class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best = 0 , smallest = INT_MAX;
        for (auto &i : prices) {
            smallest = min(smallest, i);
            best = max(best, i - smallest);
        };
        return best ; 
    }
};