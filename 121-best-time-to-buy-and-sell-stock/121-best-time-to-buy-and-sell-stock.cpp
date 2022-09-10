class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() , max_profit = 0 , min_yet = prices[0] ;
        for (int i = 1 ; i < n ; i++) {
            max_profit = max(max_profit , prices[i] - min_yet) ;
            min_yet = min(min_yet , prices[i]) ;
        }
        return max_profit ;
    }
};