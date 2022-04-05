class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0 , r = height.size() - 1 ; 
        int ans = 0 ;
        while(l < r){
            int h = min(height[l], height[r]) ; 
            ans = max(ans , (r - l) * h) ;
            while(l < r && height[l] <= h)  l++ ;
            while(r > l && height[r] <= h)  r-- ; 
        }
        return ans ;
    }
};