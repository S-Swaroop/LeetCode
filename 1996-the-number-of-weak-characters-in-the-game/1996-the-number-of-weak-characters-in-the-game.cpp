class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin() , properties.end() , comp) ;
        int weak = 0 , max_defence = INT_MIN ;
        for (int i = properties.size() - 1 ; i >= 0 ; i--) {
            if (properties[i][1] < max_defence) {
                weak++ ;
            }
            max_defence = max(max_defence , properties[i][1]) ;
        }
        return weak ;
    }
private: 
    static bool comp (vector<int> &a , vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] > b[1] ;
        } else {
            return a[0] < b[0] ;
        }
    }
};