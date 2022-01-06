class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size() ; 
        vector<int> capacity_at_dist(1002 , 0) ; 
        for(int i = 0 ; i < n ; i++){
            capacity_at_dist[trips[i][1] + 1] += trips[i][0] ;
            capacity_at_dist[trips[i][2] + 1] -= trips[i][0] ; 
        }
        for(int i = 1 ; i <= 1000 ; i++){
             capacity_at_dist[i] += capacity_at_dist[i - 1] ;
            if(capacity_at_dist[i] > capacity)  return false ; 
        }
        return true ; 
    }
};