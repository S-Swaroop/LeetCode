class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size() ;
        for(int i = 0 ; i < sz ; i++){
            int curr = flowerbed[i] ;
            int prev = (i > 0 ? flowerbed[i - 1] : 0) ; 
            int next = (i < sz - 1 ? flowerbed[i + 1] : 0) ;
            if(curr == 0 && prev == 0 && next == 0){
                n-- ; 
                flowerbed[i] = 1 ; 
            }
        }
        return (n <= 0) ; 
    }
};