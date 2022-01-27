class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *head = new Trie() ; 
        for(int &i : nums)  insert(i , head) ; 
        return findMaxXorPair(nums , head) ; 
    }
private: 
    struct Trie {
        Trie *left , *right ; 
    };
    
    void insert(int val , Trie *root) {
        Trie *curr = root ;
        for(int i = 30 ; i >= 0 ; i--) {
            if((1 & (val >> i)) == 0) {
                if(!curr->left) curr->left = new Trie() ; 
                curr = curr->left ; 
            } else {
                if(!curr->right)    curr->right = new Trie() ; 
                curr = curr->right ; 
            }
        }
    }
    
    int findMaxXorPair(vector<int>& a , Trie *head) {
        int max_xor = INT_MIN ; 
        for(int &i : a) {
            Trie *curr = head ; 
            int curr_xor = 0 ; 
            for(int j = 30 ; j >= 0 ; j--) {
                if(((i >> j) & 1) == 1) {
                    if(curr->left) {
                        curr_xor += (1 << j) ; 
                        curr = curr->left ; 
                    } else {
                        curr = curr->right ; 
                    }
                } else {
                    if(curr->right) { 
                        curr_xor += (1 << j) ; 
                        curr = curr->right ; 
                    } else {
                        curr = curr->left ; 
                    }
                }
            }
            max_xor = max(max_xor , curr_xor) ; 
        }
        return max_xor ; 
    }
    
};