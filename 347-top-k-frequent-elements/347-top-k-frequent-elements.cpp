class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int , int> freq ; 
        for (int &i : nums) {
            freq[i]++ ;
        }
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> q ; 
        for (auto &i : freq) {
            q.push({i.second , i.first}) ;
            if(q.size() > k) {
                q.pop() ;
            }
        }
        vector<int> ans ;
        while (!q.empty()) {
            ans.push_back(q.top().second) ; 
            q.pop() ;
        }
        return ans ; 
    }
};