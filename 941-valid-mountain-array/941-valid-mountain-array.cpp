class Solution {
public:
    bool validMountainArray(vector<int>& a) {
        if(a.size() < 3) return false ; 
        for(int i = 1 , n = a.size() ; i < n ; i++){
            if(a[i] < a[i - 1]){
                if(i == 1)  return false ;
                for(int j = i ; j < n ; j++){
                    if(a[j] >= a[j - 1])    return false ; 
                }
                return true ; 
            }else if(a[i] > a[i - 1]){
                continue ; 
            }else{
                return false ;
            }
        }
        return false ; 
    }
};