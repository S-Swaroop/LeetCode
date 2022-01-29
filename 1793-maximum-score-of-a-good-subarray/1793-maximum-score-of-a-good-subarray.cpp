class Node { 
public: 
    int start , end , min ; //here min is storing index of minimum element in the segment NOT the actual minimum value
    Node *left , *right ; 
    Node(int _start , int _end) {
        this->start = _start ; 
        this->end = _end ; 
        this->left = this->right = NULL ; 
    };
};
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size() ; 
        Node *root = build(nums , 0 , n - 1) ;
        return best(nums , 0 , n - 1 , root , k) ; 
    }
private: 
    Node* build(vector<int> &nums , int start , int end) {//building the segment tree recursively
        if (start > end)    return NULL ; 
        Node *root = new Node(start , end) ; 
        if (start == end) {
            root->min = start ; 
            return root ; 
        }
        int mid = (start + end) / 2 ;
        root->left = build(nums , start , mid) ; 
        root->right = build(nums , mid + 1 , end) ; 
        root->min = nums[root->left->min] < nums[root->right->min] ? root->left->min : root->right->min ;
        return root ; 
    }
    int query(vector<int> &nums , int start , int end , Node *root) {
        if (!root || end < root->start || start > root->end)    return -1 ; //out of bounds 
        if (start <= root->start && end >= root->end) { 
            return root->min ;
        }
        int left_min = query(nums , start , end , root->left) ; 
        int right_min = query(nums , start , end , root->right) ; 
        if(left_min == -1)   return right_min ;
        if(right_min == -1)  return left_min ;
        return (nums[left_min] < nums[right_min] ? left_min : right_min) ;
    }
    int best(vector<int> &nums , int start , int end , Node *root , int k) {
        int min_index = query(nums , start , end , root) ;
        if(min_index == k) {
            return nums[k] * (end - start + 1) ;
        } else if (min_index < k) {
            return max(nums[min_index] * (end - start + 1) , best(nums , min_index + 1 , end , root , k)) ;
        } else {
            return max(nums[min_index] * (end - start + 1) , best(nums , start , min_index - 1 , root , k)) ;
        }
    }
};