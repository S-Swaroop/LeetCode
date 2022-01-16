class Solution {
public:
    int maxDistToClosest(vector<int>& a) {
        int n = a.size() ;
        int ans = 0 ; 
        int left_end = 0 , right_end = 0 ; 
        for(int i = 0 ; i < n ; i++){
            if(a[i] == 1){
                left_end = i ; 
                break ; 
            }
        }    
        for(int i = n - 1 ; i >= 0 ; i--){
            if(a[i] == 1){
                right_end = n - i - 1 ; 
                break ; 
            }
        }
        int last = left_end ; 
        for(int i = left_end + 1 ; i < n ; i++){
            if(a[i]){
                ans = max(ans , (i - last) / 2) ;
                last = i ; 
            }
        }
        return max({ans , left_end , right_end}) ;
    }
};