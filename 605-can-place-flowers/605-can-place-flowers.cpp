class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size() , curr , prev , next ;
        for(int i = 0 ; i < sz && n > 0 ; i++){
            curr = flowerbed[i] ;
            prev = (i > 0 ? flowerbed[i - 1] : 0) ; 
            next = (i < sz - 1 ? flowerbed[i + 1] : 0) ;
            if(!curr && !prev && !next){
                n-- ; 
                flowerbed[i] = 1 ; 
            }
        }
        return (n <= 0) ; 
    }
};
