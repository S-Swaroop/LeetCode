class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size() ; 
        int best_overlap = 0 ; 
        for (int dx = -1 * n ; dx <= n ; dx++) {
            for (int dy = -1 * n ; dy <= n ; dy++) {
                int overlap = 0 ;
                for (int i = 0 ; i < n ; i++) {
                    for (int j = 0 ; j < n ; j++) {
                        if ((i + dx < n && i + dx >= 0) && (j + dy < n && j + dy >= 0)) {
                            overlap += (img1[i + dx][j + dy] & img2[i][j]) ;
                        }
                    }
                }
                best_overlap = max(best_overlap , overlap) ;
            }
        }
        return best_overlap ;
    }
};