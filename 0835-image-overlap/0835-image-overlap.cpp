class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size() ;
        vector<int> a , b ; 
        unordered_map<int , int> count ;
        for (int i = 0 ; i < n * n ; i++) {
            if (img1[i / n][i % n] == 1) {
                a.push_back((i / n) * 100 + (i % n)) ;
            }
            if (img2[i / n][i % n] == 1) {
                b.push_back((i / n) * 100 + (i % n)) ;
            }
        }
        
        for (int i : a) {
            for (int j : b) {
                count[j - i]++ ;
            }
        }
        
        int ans = 0 ; 
        for (auto &i : count) {
            ans = max(ans , i.second) ;
        }
        
        return ans ;
        
        // int n = img1.size() ; 
        // int best_overlap = 0 ; 
        // for (int dx = -1 * n ; dx <= n ; dx++) {
        //     for (int dy = -1 * n ; dy <= n ; dy++) {
        //         int overlap = 0 ;
        //         for (int i = 0 ; i < n ; i++) {
        //             for (int j = 0 ; j < n ; j++) {
        //                 if ((i + dx < n && i + dx >= 0) && (j + dy < n && j + dy >= 0)) {
        //                     overlap += (img1[i + dx][j + dy] & img2[i][j]) ;
        //                 }
        //             }
        //         }
        //         best_overlap = max(best_overlap , overlap) ;
        //     }
        // }
        // return best_overlap ;
    }
};