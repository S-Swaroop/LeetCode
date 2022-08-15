class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string , bool> present ; 
        unordered_map<string , int> dist ;
        for (string &i : wordList) {
            dist[i] = 0 ;
            present[i] = true ;
        }
        queue<string> q ; 
        q.push(beginWord) ;
        dist[beginWord] = 1 ;
        while (!q.empty()) {
            string word = q.front() ;
            q.pop() ; 
            int d = dist[word] ;
            if (word == endWord) {
                return d ;
            } else {
                for (char &c : word) {
                    for (char i = 'a' ; i <= 'z' ; i++) {
                        if (i != c) {
                            swap(i , c) ;
                            if (present[word]) {
                                present[word] = false ;
                                q.push(word) ;
                                dist[word] = d + 1 ;
                            }
                            swap(i , c) ;
                        }
                    }
                }
            }
        }
        return 0 ;
    }
};