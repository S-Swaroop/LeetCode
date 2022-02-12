class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map <string , bool> present ;
        unordered_map <string , int> dist ;
        for (string &i : wordList) {
            present[i] = 1 ;
        }
        if (!present[endWord]) {
            return 0 ;
        }
        dist[beginWord] = 0 ;
        queue <string> q ;
        q.push(beginWord) ;
        while (!q.empty()) {
            string node = q.front() ;
            q.pop() ;
            int d = dist[node] ;
            if (node == endWord) {
                return d + 1 ;
            }
            for (char &c : node) {
                for (char x = 'a' ; x <= 'z' ; x++) {
                    if (x != c) {
                        swap(x , c) ;
                        if (present[node]) {
                            present[node] = 0 ;
                            dist[node] = d + 1 ;
                            q.push(node) ;
                        }
                        swap(x , c) ;
                    }
                }
            }
        }
        return 0 ;
    }
};