class Solution {
public:
    string minWindow(string s, string t) {
        map<char , int> letters ; 
        for(char i : t) letters[i]++ ; 
        int count = 0 ;//number of t's letters in current window
        int l = 0 , r = 0 , _min = INT_MAX , start = 0 ; 
        while(r < s.length()){
            if(letters[s[r]] > 0)   count++ ;//this letter is present in t 
            letters[s[r]]-- ; 
            if(count == t.length()){
                while(l <= r && letters[s[l]] < 0){
                    letters[s[l]]++ ;
                    l++ ; 
                }
                if(_min > r - l){
                    _min = r - l + 1 ; 
                    start = l ; 
                }
                letters[s[l]]++ ; 
                l++ ; 
                count-- ; 
            }
            r++ ; 
        }
        if(_min == INT_MAX) return "" ; 
        else    return s.substr(start , _min) ; 
    }
};