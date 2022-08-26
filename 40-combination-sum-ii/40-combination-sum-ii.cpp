class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end()) ;
        vector<vector<int>> ans ; 
        vector<int> curr ;
        f (0 , candidates , curr , ans , target) ;
        return ans ;
    }
private: 
    void f (int index ,vector<int> &a , vector<int> &curr , vector<vector<int>> &ans , int target) {
        if (target == 0) {
            ans.push_back(curr) ;
            return ;
        } else if (index == (int)a.size()) {
            return ;
        } else {
            for (int i = index ; i < (int)a.size() ; i++) {
                if (i > index && a[i] == a[i - 1]) {
                    continue ;
                } else if (target >= a[i]) {
                    curr.push_back(a[i]) ;
                    f(i + 1 , a , curr , ans , target - a[i]) ;
                    curr.pop_back() ;
                }
            }
            return ;
        }
    }
};