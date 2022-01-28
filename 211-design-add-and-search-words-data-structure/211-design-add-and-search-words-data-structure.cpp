class TrieNode {
    public : 
        TrieNode* children[26] ; 
        bool endsHere ; 
    
        TrieNode() {
            endsHere = false ; 
            for(int i = 0 ; i < 26 ; i++) {
                children[i] = NULL ;
            }
        }
};
class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* node = root ; 
        for(char i : word) {
            if(!node->children[i - 'a'])    node->children[i - 'a'] = new TrieNode() ; 
            node = node->children[i - 'a'] ;
        }
        node->endsHere = true ; 
    }
    
    bool search(string word) {
        return find(word.c_str() , root) ; 
    }
private: 
    TrieNode* root = new TrieNode() ; 
    
    bool find(const char* word, TrieNode *root) {
        TrieNode *node = root ; 
        for(int i = 0 ; word[i] && node ; i++){
            if(word[i] != '.') {
                node = node->children[word[i] - 'a'] ;
            } else {
                TrieNode *temp = node ; 
                for(int j = 0 ; j < 26 ; j++) {
                    node = temp->children[j] ; 
                    if(find(word + i + 1 , node)) {
                        return true ; 
                    }
                }
            }
        }
        return node && node->endsHere ; 
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */