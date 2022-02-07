class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char , int> f ; 
        for (char &i : s)   f[i]++ ; 
        for (char &i : t) {
            if (f.find(i) == f.end() || f[i] == 0) {
                return i ; 
            } else {
                f[i]-- ;
                if (f[i] == 0)  f.erase(i) ; 
            }
        }
        return f.begin()->first ;
    }
};