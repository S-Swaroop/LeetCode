class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() ;
        int ans = INT_MAX ;
        int totalSum = accumulate(nums.begin() , nums.end() , 0) ;
        int target = totalSum / 2 ;
        vector<vector<int>> left(n / 2 + 1) , right(n / 2 + 1) ;
        generate(0 , n / 2 - 1 , nums , left , right) ; 
        // generate(n / 2 , n - 1 , nums , right) ;
        for (int i = 0  ; i < n / 2 + 1 ; i++) {
            for (int j = 0 ; j < (int)left[i].size() ; j++) {
                auto it = lower_bound(right[n / 2 - i].begin() , right[n / 2 - i].end() , target - left[i][j]) ;
                if (it == right[n / 2 - i].end()) {
                    it-- ;
                }
                ans = min(ans , abs((totalSum - (left[i][j] + *it)) - (left[i][j] + *it))) ;
                if (it != right[n / 2 - i].begin()) {
                    --it ;
                    ans = min(ans , abs((totalSum - (left[i][j] + *it)) - (left[i][j] + *it))) ;
                    ++it ;
                }
                ++it ; 
                if (it != right[n / 2 - i].end()) {
                    ans = min(ans , abs((totalSum - (left[i][j] + *it)) - (left[i][j] + *it))) ;
                }
            }
        }
        return ans ;
    }
private: 
    void generate (int start , int end , vector<int> &nums , vector<vector<int>> &a , vector<vector<int>> &b) {
        int n = end - start + 1 ;
        int lim = 1 << n ;
        for (int i = 0 ; i < lim ; i++) {
            int chosen = __builtin_popcount(i) ;
            int sum1 = 0 , sum2 = 0 ;
            for (int j = start ; j <= end ; j++) {
                if ((1 << (j - start)) & i) {
                    sum1 += nums[j] ;
                    sum2 += nums[j + end + 1] ;
                }
            }
            b[chosen].push_back(sum2) ;
            a[chosen].push_back(sum1) ;
        }
        for (int i = 0 ; i < (int)a.size() ; i++) {
            sort(a[i].begin() , a[i].end()) ;
            sort(b[i].begin() , b[i].end()) ;
        }
    }
    
};