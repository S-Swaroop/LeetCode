class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int , pair<int,int>>> q ; 
        for(auto i : points){
            int dist = i[0]*i[0] + i[1]*i[1] ;
            q.push({-dist , {i[0] , i[1]}}) ;
        }
        vector<vector<int>> ans ; 
        while(k--){
            auto p = q.top() ;
            ans.push_back({p.second.first , p.second.second}) ;
            q.pop() ;
        }
        return ans ; 
    }
};