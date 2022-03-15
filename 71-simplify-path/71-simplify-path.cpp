class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s ; 
        string dir = "" ; 
        for (char c : path) {
            if (c == '/') {
                insert(dir , s) ;
            } else {
                dir += c ; 
            }
        }
        insert(dir , s) ;
        return construct(s) ;
    }
private: 
    void insert (string &dir , vector<string> &path) {
        if (!dir.empty()) {
            if (dir == "..") {
                if (!path.empty()) {
                    path.pop_back() ;
                }
            } else if (dir == ".") {

            } else {
                path.push_back(dir) ;
            }
            dir.clear() ;
        }
    }
    string construct (vector<string> &path) {
        string ans = "/" ; 
        for (string &i : path) {
            ans += i + "/" ;
        }
        if (ans.size() > 1)
            ans.pop_back() ;
        return ans ; 
    }
};