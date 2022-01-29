class Solution {
public:
    bool isOpening(char c) {
        return (c == '(' || c == '{' || c == '[') ;
    }
    bool isSameType(char a , char b) {
        return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']')) ;
    }
    bool isValid(string s) {
        stack<char> st ; 
        for(char c : s) {
            if(isOpening(c)) {
                st.push(c) ; 
            } else {
                if (!st.empty() && isSameType(st.top() , c)) {
                    st.pop() ; 
                } else {
                    return false ; 
                }
            }
        }
        return st.empty() ; 
    }
};