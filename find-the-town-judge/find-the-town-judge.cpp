class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> f(n + 1 , 0) , g(n + 1 , 0); 
        for(auto &i : trust){
            f[i[1]]++ ; 
            g[i[0]]++ ;
        }
        vector<int> ans ; 
        for(int i = 1 ; i <= n ; i++){
            if(f[i] == n - 1 && g[i] == 0){
                ans.push_back(i) ; 
            }
        }
        if(ans.empty() || ans.size() > 1)  return -1 ; 
        else    return ans[0] ; 
    }
};