class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size() ;
        RMQ G(n , nums) ;
        vector<int> ans ; 
        for (int i = 0 ; i + k - 1 < n ; i++) {
            ans.push_back(G.query(1 , 0 , n - 1 , i , i + k - 1)) ;
        }
        return ans ;
    }
private:
    /*
*   Range Max Query (0-indexing!!!)
*   Tree Construction: O(N)
*   Query in Range: O(logN)
*   Updating an element: O(logN)
*   for max of a[l,....,r] : query (1 , 0 , n - 1 , l , r) [l and r are in 0-indexing]
*   for update at index pos : update (1 , 0 , n - 1 , pos , new_val)
*/
struct RMQ {
    int N ;
    int *tree ; 
    //constructor
    RMQ (int n , vector<int> &a) {
        N = n ;
        tree = new int[(4 * n) + 1] ;
        build(1 , 0 , n - 1 , a) ; 
    }
    //function to recursively build the tree
    void build (int vertex , int tl , int tr , vector<int> &a) {
        if (tl == tr) {
            tree[vertex] = a[tl] ;
        } else {
            int tm = (tl + tr) >> 1 ; 
            build(2 * vertex , tl , tm , a) ;
            build((2 * vertex) + 1 , tm + 1 , tr , a) ;
            tree[vertex] = max(tree[2 * vertex] , tree[(2 * vertex) + 1]) ;
        }
    }
    //function to update values 
    void update (int vertex , int tl , int tr , int pos , int new_val) {
        if (tl == tr) {
            tree[vertex] = new_val ;
        } else {
            int tm = (tl + tr) >> 1 ; 
            if (pos <= tm) {
                update(2 * vertex , tl , tm , pos , new_val) ;
            } else {
                update((2 * vertex) + 1 , tm + 1 , tr , pos , new_val) ;
            }
            tree[vertex] = max(tree[2 * vertex] , tree[(2 * vertex) + 1]) ;
        }
    }
    // function to query min element in a[l, .... , r] (0-indexed)
    int query (int vertex , int tl , int tr , int l , int r) {
        if (l > r) {
            return INT_MIN ;
        } else if (tl == l && tr == r) {
            return tree[vertex] ;
        } else {
            int tm = (tl + tr) >> 1 ; 
            return max(query(2 * vertex , tl , tm , l , min(tm , r)) , query((2 * vertex) + 1 , tm + 1 , tr , max(l , tm + 1) , r)) ;
        }
    }
};
};