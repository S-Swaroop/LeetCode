class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q ; 
        for (vector<int> &i : matrix) {
            for (int &j : i) {
                q.push(j) ; 
                if (q.size() > k) {
                    q.pop() ; 
                }
            }
        }
        return q.top() ;
    }
};