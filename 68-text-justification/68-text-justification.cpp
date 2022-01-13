class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size() ; 
        string line = "" ;
        vector<string> text ; 
        for(int i = 0 ; i < n ; i++){
            if(line.length() + words[i].length() <= maxWidth){
                line += words[i] ; 
                if(line.length() + 1 <= maxWidth){
                    line += " " ; 
                }else{
                    text.push_back(line) ; 
                    line = "" ;
                }
            }else{
                line += string(maxWidth - line.length() , ' ') ; 
                text.push_back(line) ; 
                line = "" ;
                i-- ;
            }
        }   
        if(line.length() > 0)   text.push_back(line + string(maxWidth - line.length() , ' ')) ; 
        for(int i = 0 , sz = text.size() ; i < sz - 1 ; i++){
            justify(text[i]) ; 
        }
        return text ; 
    }
private: 
    void justify(string& s){
        string spaces = "" ; 
        while(s.back() == ' '){
            spaces += " " ;
            s.pop_back() ;  
        }
        int gaps = count(s.begin() , s.end() , ' ') ;
        if(gaps == 0){
            s += spaces ; 
            return ;
        }
        int eachSpace = spaces.length() / gaps ;
        int rem = spaces.length() % gaps ; 
        for(int i = 0 ; i < s.length() - 1 ; i++){
            if(s[i] == ' '){
                while(i < s.length() - 1 && s[i] == ' ')    i++ ; 
                i-- ; 
                s = s.substr(0 , i) + string(eachSpace + min(1 , rem) , ' ') + s.substr(i) ; 
                rem = max(0 , rem - 1) ; 
                while(i < s.length() - 1 && s[i] == ' ')    i++ ; 
                i-- ; 
            }
        }
    }
};