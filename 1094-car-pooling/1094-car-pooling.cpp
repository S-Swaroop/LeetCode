class Solution {
public:
    /*
    -----
       -----
        --
             ---------
    we need to check if at any distance the number of passengers required to be picked up 
    is greater than capacity or not
    a simple partial sum trick will do 
    lets say you need to pick 'x' passengers at point 'l' and drop at point 'r',
    just add +x at point[l] and add -x at point[r]
    so while going left to right we will consider +x passengers at and after point[l] and
    -x passengers after and at point[r]
    */
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> capacity_at_dist(10005 , 0) ;
        int n = trips.size() ;
        for (int i = 0 ; i < n ; i++){
            capacity_at_dist[trips[i][1]] += trips[i][0] ;
            capacity_at_dist[trips[i][2]] -= trips[i][0] ;
        }
        int capacity_at_any_dist = 0 ;
        for (int i = 0 ; i<= 10000 ; i++){
            capacity_at_any_dist += capacity_at_dist[i] ;
            if (capacity_at_any_dist > capacity)    return false;
        }
        return true; 
    }
};