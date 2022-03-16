class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st ;
        int j = 0 , n = popped.size() ;
        for (int &i : pushed) {
            st.push(i) ; 
            while (!st.empty() && j < n && popped[j] == st.top()) {
                j++ ; 
                st.pop() ;
            }
        }
        return st.empty() ;
    }
};