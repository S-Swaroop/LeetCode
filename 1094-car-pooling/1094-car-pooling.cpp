class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size() ; 
        int _max = 0 , _min = 1001 ;
        for(auto &i : trips){
            _max = max(_max , i[2]) ;
            _min = min(_min , i[1]) ; 
        }
        vector<int> capacity_at_dist(_max - _min + 10 , 0) ; 
        for(int i = 0 ; i < n ; i++){
            capacity_at_dist[trips[i][1] - _min + 1] += trips[i][0] ;
            capacity_at_dist[trips[i][2] - _min + 1] -= trips[i][0] ; 
        }
        for(int i = 1 ; i <= _max - _min + 1 ; i++){
             capacity_at_dist[i] += capacity_at_dist[i - 1] ;
            if(capacity_at_dist[i] > capacity)  return false ; 
        }
        return true ; 
    }
};