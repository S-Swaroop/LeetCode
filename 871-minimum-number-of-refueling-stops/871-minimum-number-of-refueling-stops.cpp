class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target , -1}) ;
        priority_queue<int> pq ;
        int current_fuel = startFuel , last_station = 0 , refuels = 0 ;
        for (int i = 0 , n = stations.size() ; i < n ; i++) {
            current_fuel -= (stations[i][0] - last_station) ;
            while (!pq.empty() && current_fuel < 0) {
                current_fuel += pq.top() ;
                refuels++ ;
                pq.pop() ;
            }
            if (current_fuel < 0) {
                return -1 ;
            }
            last_station = stations[i][0] ;
            pq.push(stations[i][1]) ;
        }
        return refuels ;
    }
};