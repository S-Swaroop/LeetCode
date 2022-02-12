class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map <string , bool> present ;
        for (string &i : wordList) {
            present[i] = 1 ;
        }
        if (!present[endWord]) {
            return 0 ;
        }
        queue <pair<string , int>> q ;
        q.push({beginWord , 1}) ;
        while (!q.empty()) {
            auto node = q.front() ;
            q.pop() ;
            if (node.first == endWord) {
                return node.second ;
            }
            for (char &c : node.first) {
                for (char x = 'a' ; x <= 'z' ; x++) {
                    if (x != c) {
                        swap(x , c) ;
                        if (present[node.first]) {
                            present[node.first] = 0 ;
                            q.push({node.first , node.second + 1}) ;
                        }
                        swap(x , c) ;
                    }
                }
            }
        }
        return 0 ;
    }
};