class Solution {
public:
    int memo[501][501] ;//for memoization
    vector<int> a ; //new array to store nums array and dummy values on both ends
    int n ;//stores size of dummy array
    
    int dp(int i , int j){
        if(i > j)   return 0 ; //base case
        if(memo[i][j] != -1)    return memo[i][j] ; //if already processed 
        if(i == j){    // only one element 
            int res = a[i] ;
            if(i - 1 >= 0)  res *= a[i - 1] ;
            if(i + 1 < n)   res *= a[i + 1] ;
            return memo[i][j] = res ;
        }
        int ans = 0 ; 
/*
assuming that we burst the kth balloon AFTER we burst ballons from i -> k - 1 and k + 1 -> j
we can say that after such a series of steps, the kth balloon will now be adjacent to (i - 1)th balloon and (j + 1)th balloon
thus we can solve for the ranges [i , k - 1] and [k + 1 , j] independently now that we know in the end the sum will increase by nums[i - 1] * nums[k] * nums[j + 1] */ 
        for(int k = i ; k <= j ; k++){ 
            int temp = a[k] ; 
            if(i - 1 >= 0)  temp *= a[i - 1] ;
            if(j + 1 < n)   temp *= a[j + 1] ;
            temp += dp(i , k - 1)  + dp(k + 1 , j) ;// solving for the ranges [i , k - 1] and [k + 1 , j] recursively
            ans = max(ans , temp) ; 
        }
        return memo[i][j] = ans ; 
    }
    
    int maxCoins(vector<int>& nums) {
        a.push_back(1) ; 
        for(int i : nums)   a.push_back(i) ; 
        a.push_back(1) ; 
        n = a.size() ;
        memset(memo , -1 , sizeof(memo)) ;
        return dp(1 , n - 2) ;
    }
};