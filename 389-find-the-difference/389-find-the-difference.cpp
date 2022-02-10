class Solution {
public:
    char findTheDifference(string s, string t) {
        int hash = 0 ;
        for (char &c : t)   hash += (c - 'a') ;
        for (char &c : s)   hash -= (c - 'a') ;
        return (char)('a' + hash) ;
    }
};