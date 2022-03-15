class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st ;
        int n = s.length() ; 
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                st.push({'(' , i}) ;
            }else if(s[i] == ')'){
                if(!st.empty() && st.top().first == '('){
                    st.pop() ;
                }else{
                    st.push({')' , i}) ;
                }
            }
        }
        if(st.empty())  return s ; 
        string ans = "" ; 
        for(int i = n-1 ; i >= 0 ; i--){
            if(!st.empty() && st.top().second == i){
                st.pop() ; 
            }else{
                ans += s[i] ; 
            }
        }
        reverse(ans.begin() , ans.end()) ; 
        return ans ;
    }
};