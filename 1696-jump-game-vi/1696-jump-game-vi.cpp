class Solution {
public:
    int maxResult(vector<int>& a, int k) {
        int n = a.size() ; 
        vector<int> dp(n + 1 , INT_MIN) ; 
        dp[0] = a[0] ; 
        priority_queue<pair< int , int >> pq ;
        pq.push({dp[0] , 0}) ;
        for (int i = 1 ; i < n ; i++) {
            while (!pq.empty() && pq.top().second < i - k) {
                pq.pop() ; 
            }
            dp[i] = a[i] + pq.top().first ; 
            pq.push({dp[i] , i}) ;
        }
        return dp[n - 1] ;
    }
};