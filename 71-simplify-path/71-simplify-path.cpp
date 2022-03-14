class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s ; 
        string dir = "" ; 
        for (char c : path) {
            if (c == '/') {
                if (!dir.empty()) {
                    if (dir == "..") {
                        if (!s.empty()) {
                            s.pop_back() ;
                        }
                    } else if (dir == ".") {
                        
                    } else {
                        s.push_back(dir) ;
                    }
                    dir.clear() ;
                }
            } else {
                dir += c ; 
            }
        }
        if (!dir.empty()) {
            if (dir == "..") {
                if (!s.empty()) {
                    s.pop_back() ;
                }
            } else if (dir == ".") {

            } else {
                s.push_back(dir) ;
            }
            dir.clear() ;
        }
        string ans = "/" ;
        for (string &i : s) {
            ans += i + "/" ;
        }
        if (ans.size() > 1)
            ans.pop_back() ;
        return ans ; 
    }
};