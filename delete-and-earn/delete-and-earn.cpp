class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int , int> freq ;
        for(int i : nums)   freq[i]++ ; 
        int taking = 0 , notTaking = 0 , prev = -1 ; 
        for(auto i : freq){
            int m = max(taking , notTaking) ; 
            if(i.first != prev + 1){
                taking = i.first * i.second + m ; 
                notTaking = m ;
            } else {
                taking = i.first * i.second + notTaking ; 
                notTaking = m ; 
            }
            prev = i.first ; 
        }
        return max(taking , notTaking) ;
    }
};