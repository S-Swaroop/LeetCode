class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp , value}) ;
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) {
            return "" ;
        } else {
            int low = -1 , high = m[key].size()  ; 
            while (high - low > 1) {
                int mid = low + ((high - low) >> 1) ;
                if (m[key][mid].first <= timestamp) {
                    low = mid ; 
                } else {
                    high = mid ;
                }
            }
            return low < m[key].size() ? m[key][low].second : "" ; 
        }
    }
private: 
    map<string , vector<pair<int , string>>> m ;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */