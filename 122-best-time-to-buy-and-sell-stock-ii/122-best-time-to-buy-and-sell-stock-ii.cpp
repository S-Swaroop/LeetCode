class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; 
        //buy at local minimas and sell at next local maxima
        //assume starting to be a local minima 
        //assume ending to be a local maxima
        int profit = 0 ; 
        for(int i = 0 ; i < n - 1 ; i++){
            profit += max(0 , prices[i + 1] - prices[i]) ; 
        }
        return profit ; 
    }
};