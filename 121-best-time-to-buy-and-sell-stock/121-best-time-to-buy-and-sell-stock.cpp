class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int _min = INT_MAX , profit = 0 ; 
        for (int &i : prices) {
            _min = min(_min , i) ; 
            profit = max(profit , i - _min) ;
        }
        return profit ;
    }
};