class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size() ;
        vector<int> left , right ;
        generate(0 , n / 2 + 1 , 0 , nums , left) ;
        generate(n / 2 + 1 , n , 0 , nums , right) ;
        sort(left.begin() , left.end()) ;
        sort(right.begin() , right.end()) ;
        int ans = abs(goal) ; 
        for (int i = 0 ; i < (int)left.size() ; i++)    ans = min(ans , abs(goal - left[i])) ;
        for (int i = 0 ; i < (int)right.size() ; i++)    ans = min(ans , abs(goal - right[i])) ;
        search(left , right , ans , goal) ;
        return ans ;
    }
private:
    // recursive function to generate all possible subset sum in a range and store them in the container
    void generate (int index , int end , int sum , vector<int> &a , vector<int> &container) {
        if (index == end) {
            return container.push_back(sum) ;
        } else {
            // don't take current element
            generate (index + 1 , end , sum , a , container) ;
            // take current element
            generate (index + 1 , end , sum + a[index] , a , container) ;
        }
    }
    
    void search(vector<int>&left , vector<int>&right , int &ans , int target) {
        int l = 0 ; 
        int r = right.size() - 1 ; 
        while(l < left.size() && r >= 0) {
            int ss = left[l] + right[r] ; 
            ans = min(ans , abs(target - ss)) ; 
            if(ss < target) l++ ; 
            else if(ss > target) r-- ; 
            else break ; 
        }
    }
};