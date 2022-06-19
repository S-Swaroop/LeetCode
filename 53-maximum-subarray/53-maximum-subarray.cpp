class Solution {
public:
    int maxSubArray(vector<int> a) {
        int n = a.size() ; 
        int sum = 0 , max_yet = a[0] ; 
        for(int i = 0 ; i < n ; i++){
            sum += a[i] ;
            max_yet = max(max_yet, sum) ;
            sum = max(sum , 0) ;
        }
        return max_yet ; 
    }
};