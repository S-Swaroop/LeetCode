class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size() ;
        if(sz == 1){
            if(flowerbed[0])   return n == 0 ; 
            else    return n <= 1 ;
        }
        if(!flowerbed[1] && !flowerbed[0])  flowerbed[0] = 1 , n-- ; 
        if(!flowerbed[sz - 1] && !flowerbed[sz - 2])  flowerbed[sz - 1] = 1 , n-- ; 
        for(int i = 1 , sz = flowerbed.size() ; i < sz - 1 ; i++){
            if(!flowerbed[i - 1] && !flowerbed[i] && !flowerbed[i + 1])  n-- , i++ , cout << i << " " ; 
        }
        return n <= 0 ;
    }
};