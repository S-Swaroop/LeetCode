class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &i : tickets) {
            adj[i[0]].insert(i[1]) ;
        }
        dfs("JFK") ;
        reverse(itinerary.begin() , itinerary.end()) ;
        return itinerary ; 
    }
private: 
    vector<string> itinerary ; 
    unordered_map<string , multiset<string>> adj ;  // We use priority queue for lexographic ordering
    
    void dfs(string node) {
        while (!adj[node].empty()) {
            string to = *adj[node].begin() ;
            adj[node].erase(adj[node].begin()) ;
            dfs(to) ;
        }
        itinerary.push_back(node) ; 
    }
};