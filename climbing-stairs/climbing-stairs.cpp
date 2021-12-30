class Solution {
public:
    vector<int> memo ;
    int stairs(int n) {
        if(n == 1 || n == 2)    return n ;
        if(memo[n] != 0)    return memo[n] ; 
        return memo[n] = stairs(n - 1) + stairs(n - 2) ; 
    }
    int climbStairs(int n) {
        memo.resize(n + 1 , 0) ; 
        return stairs(n) ; 
    }
};