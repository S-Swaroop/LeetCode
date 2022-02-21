class Solution {
public:
    int majorityElement(vector<int>& a) {
        int curr = a[0] ; 
        int curr_freq = 1 ;
        for(int i = 1 , n = a.size() ; i < n ; i++){
            if(a[i] == curr)    curr_freq++ ; 
            else    curr_freq-- ; 
            if(curr_freq == 0){
                i++ ; 
                curr = a[i] ; 
                curr_freq = 1 ; 
            }
        }
        return curr ; 
    }
    
};