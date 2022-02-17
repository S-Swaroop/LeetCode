class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ; 
        vector<int> combo ;
        generate(0 , candidates , target , combo , ans) ;
        return ans ;
    }
private:
    void generate(int i , vector<int> &candidates , int target , vector<int> &combo , vector<vector<int>> &ans) {
        if (i == candidates.size()) {
            return ;
        }
        if (target == 0) {
            ans.push_back(combo) ; 
            return ; 
        }
        if (target >= candidates[i]) {
            combo.push_back(candidates[i]) ; 
            generate(i , candidates , target - candidates[i] , combo , ans) ;
            combo.pop_back() ; //backtracking step
            generate(i + 1 , candidates , target , combo , ans) ;
        } else {
            generate(i + 1 , candidates , target , combo , ans) ;
        }
        return ;
    }
};