class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; 
        int min_yet = INT_MAX ;
        stack<int> max_next ; 
        for(int i = n - 1 ; i >= 0 ; i--){
            if(max_next.empty()){
                max_next.push(prices[i]) ; 
            }else if(prices[i] >= max_next.top()){
                max_next.push(prices[i]) ; 
            }
        }
        int profit = 0 ; 
        for(int i = 0 ; i < n - 1 ; i++){
            min_yet = min(min_yet , prices[i]) ;
            if(max_next.top() == prices[i]){
                max_next.pop() ; 
            }
            profit = max(profit , max_next.top() - min_yet) ;
        }
        return profit ; 
    }
};