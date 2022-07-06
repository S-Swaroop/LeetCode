class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0 ;
        stack<int> st ; 
        for (int i = 0 , n = height.size() ; i < n ; i++) {
            while (!st.empty() && height[st.top()] < height[i]) {
                int j = st.top() ; 
                st.pop() ; 
                if (st.empty()) {
                    break ;
                }
                area += (min(height[i] , height[st.top()]) - height[j]) * (i - st.top() - 1) ;
            }
            st.push(i) ; 
        }
        return area ;
    }
};