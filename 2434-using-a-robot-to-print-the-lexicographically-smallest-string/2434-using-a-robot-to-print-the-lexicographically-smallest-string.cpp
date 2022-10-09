class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26 , 0) ;
        for (char &i : s) {
            freq[i - 'a']++ ;
        }
        string t = "" , paper = "" ;
        for (char &i : s) {
            // give it to robot
            t += i ; 
            // decrease given character's frequency
            freq[i - 'a']-- ;  
            // retrieve smallest character present in string s
            char _min = getMin(freq) ; 
            // if robot has a character smaller than equal to _min then write it to paper
            while (!t.empty() && t.back() <= _min) { 
                paper += t.back() ;
                t.pop_back() ;
            }
        }
        // write all characters left with robot
        while (!t.empty()) {
            paper += t.back() ; 
            t.pop_back() ;
        }
        return paper ;
    }
private:  
    char getMin (vector<int> &freq) {
        for (int i = 0 ; i < 26 ; i++) {
            if (freq[i]) {
                return ('a' + i) ;
            }
        }
        return 'z' ;
    }
};