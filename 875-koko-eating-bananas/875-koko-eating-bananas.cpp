class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 0 , high = 1e9 + 1 ;
        while (high - low > 1) {
            int mid = low + ((high - low) >> 1) ; 
            if (possible(piles , mid , h)) {
                high = mid ; 
            } else {
                low = mid ; 
            }
        }
        return high ;
    }
private: 
    bool possible (vector<int> &piles , int k , int h) {
        for (int &i : piles) {
            h -= (i + k - 1) / k ; 
        }
        return h >= 0 ;
    }
};