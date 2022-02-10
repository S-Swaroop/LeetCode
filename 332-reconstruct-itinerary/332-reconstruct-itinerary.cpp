class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &i : tickets) {
            adj[i[0]].push(i[1]) ;
        }
        dfs("JFK") ;
        reverse(itinerary.begin() , itinerary.end()) ;
        return itinerary ; 
    }
private: 
    vector<string> itinerary ; 
    unordered_map<string , priority_queue<string , vector<string> , greater<string>>> adj ;  // We use priority queue for lexographic ordering
    
    void dfs(string node) {
        while (!adj[node].empty()) {
            string to = adj[node].top() ;
            adj[node].pop() ;
            dfs(to) ;
        }
        itinerary.push_back(node) ; 
    }
};