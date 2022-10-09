class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26 , 0) ;
        for (char &i : s) {
            freq[i - 'a']++ ;
        }
        int low = 0 ;
        // global min character
        char _min = 'z' ;
        string t = "" , paper = "" ;
        for (char &i : s) {
            // give it to robot
            t += i ; 
            // decrease given character's frequency
            freq[i - 'a']-- ;  
            // move low to the smallest character in string s
            while (low < 26 && freq[low] == 0) {
                low++ ;
            }
            _min = 'a' + low ;
            // if robot has a character smaller than equal to _min then write it to paper
            while (!t.empty() && t.back() <= _min) { 
                paper += t.back() ;
                t.pop_back() ;
            }
        }
        return paper ;
    }
};