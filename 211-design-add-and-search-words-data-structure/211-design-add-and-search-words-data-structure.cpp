struct TrieNode {
    struct TrieNode* children[26] ;
    bool isEndOfWord ;
    TrieNode () {
        memset(children , NULL , sizeof(children)) ;
        isEndOfWord = false ;
    };
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode() ;
    }
    
    void addWord(string word) {
        TrieNode *node = root ;
        for (char &i : word) {
            if (!node->children[i - 'a']) {
                node->children[i - 'a'] = new TrieNode() ;
            }
            node = node->children[i - 'a'] ;
        }
        node->isEndOfWord = true ;
    }
    
    bool search(string word) {
        return find(0 , root , word) ;
    }
private:
    TrieNode *root ;
    inline bool find (int _i , TrieNode *root , string &word) {
        TrieNode *node = root ; 
        int n = word.length() ;
        for (int i = _i ; i < n && node ; i++) {
            if (word[i] == '.') {
                for (int j = 0 ; j < 26 ; j++) {
                    if (find(i + 1 , node->children[j] , word)) {
                        return true ;
                    }
                }
                return false ;
            } else {
                node = node->children[word[i] - 'a'] ;
            }
        }
        return node && node->isEndOfWord ;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */