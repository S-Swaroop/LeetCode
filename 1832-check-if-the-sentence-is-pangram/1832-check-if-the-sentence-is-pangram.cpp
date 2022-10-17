class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> f(26 , 0) ;
        for (char &i : sentence) {
            f[i - 'a']++ ;
        }
        for (int i = 0 ; i < 26 ; i++) {
            if (f[i] == 0) {
                return false ;
            }
        }
        return true ;
    }
};