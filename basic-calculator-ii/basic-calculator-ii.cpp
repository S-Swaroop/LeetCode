class Solution {
public:
    int calculate(string s) {
        int n = s.length() ; 
        stack<int> st ; 
        int curr = 0 ;
        char op = '+' ;
        for(int i = 0 ; i < n ; i++){
            if(isdigit(s[i])){
                curr = curr * 10 + (s[i] - '0') ;
            }
            if(!isdigit(s[i]) && !iswspace(s[i]) || i == n - 1){
                if(op == '+'){
                    st.push(curr) ; 
                }else if(op == '-'){
                    st.push(-curr) ; 
                }else if(op == '/'){
                    int temp = st.top() ; 
                    st.pop() ; 
                    st.push(temp / curr) ;
                }else{
                    int temp = st.top() ; 
                    st.pop() ; 
                    st.push(temp * curr) ;
                }
                op = s[i] ; 
                curr = 0 ; 
            }
        }
        int res = 0 ; 
        while(!st.empty()){
            res += st.top() ; 
            st.pop() ;
        }
        return res ; 
    }
};
