class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // // map word to frequency
        // unordered_map<string , int> freq ; 
        // for (string &i : words) {
        //     freq[i]++ ;
        // }
        // int n = freq.size() ; 
        // // mapping frequency to a set of words which have that frequency
        // vector<set<string>> f(n + 1) ; 
        // for (string &s : words) {
        //     f[freq[s]].insert(s) ;
        // }
        // vector<string> ans ;
        // // just select first K words according to the priority
        // for (int i = n ; i >= 1 && (int)ans.size() < k ; i--) {
        //     for (string j : f[i]) {
        //         ans.push_back(j) ; 
        //         if ((int)ans.size() == k) {
        //             break ;
        //         }
        //     }
        // }
        // return ans ; 
        unordered_map<string , int> f ; 
        for (string &s : words) {
            f[s]++ ;
        }
        int n = f.size() ; 
        vector<struct TrieNode*> fr(n + 1) ;
        for (int i = 1 ; i <= n ; i++) {
            fr[i] = new TrieNode() ;
        }
        for (auto &[word , freq] : f) {
            insert(fr[freq] , word) ;
        }
        vector<string> ans ;
        for (int i = n ; i >= 1 ; i--) {
            getWord(fr[i] , ans , k) ;
        }
        return ans ;
    }
private:
    struct TrieNode {
        struct TrieNode* children[26] ;
        string word ; 
        bool isEndOfWord ;
        TrieNode () {
            word = "" ; 
            isEndOfWord = false ;
            for (int i = 0 ; i < 26 ; i++)  children[i] = nullptr ;
        }
    };
    
    void insert (struct TrieNode *root , string word) {
        struct TrieNode *curr = root ; 
        for (char &i : word) {
            if (!curr->children[i - 'a']) {
                curr->children[i - 'a'] = new TrieNode() ;
            }
            curr = curr->children[i - 'a'] ;
        }
        curr->isEndOfWord = true ;
        curr->word = word ;
    }
    
    void getWord (struct TrieNode *root , vector<string> &res , int k) {
        if (!root) {
            return ;
        } else if ((int)res.size() == k) {
            return ;
        } else {
            if (root->isEndOfWord) {
                res.push_back(root->word) ;
            }
            struct TrieNode *curr = root ; 
            for (int i = 0 ; i < 26 ; i++) {
                if (curr->children[i]) {
                    getWord(curr->children[i] , res , k) ;
                }
            }
        }
    }
};