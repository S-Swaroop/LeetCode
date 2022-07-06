class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int , int> freq ; 
        for (int &i : nums) {
            freq[i]++ ;
        }
        priority_queue<pair<int , int>> q ; 
        for (auto &i : freq) {
            q.push({i.second , i.first}) ;
        }
        vector<int> ans ;
        while (k--) {
            ans.push_back(q.top().second) ; 
            q.pop() ;
        }
        return ans ; 
    }
};