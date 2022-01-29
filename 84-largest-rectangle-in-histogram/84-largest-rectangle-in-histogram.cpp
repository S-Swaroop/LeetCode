class SegmentTree {
public: 
    int start , end , min ; 
    SegmentTree *left ;
    SegmentTree *right ;
    
    SegmentTree (int start, int end) {
        this->start = start ;
        this->end = end ;
        left = right = NULL ;
    }  
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        SegmentTree* root = build(heights , 0 , heights.size() - 1) ;
        return maxAreaInThisSegment(heights , 0 , heights.size() - 1 , root) ;
    }
    
    SegmentTree* build(vector<int>& heights, int start, int end) {
        if (start > end) return NULL ;
        SegmentTree *root = new SegmentTree(start, end) ;
        if (start == end) {
            root->min = start ;
        return root ;
        } else {
          int middle = (start + end) / 2 ;
          root->left = build(heights, start, middle) ;
          root->right = build(heights, middle + 1, end) ;
          root->min = heights[root->left->min] < heights[root->right->min] ? root->left->min : root->right->min ;
          return root ;
        }
    }
    
    int query(vector<int> &heights , int start , int end , SegmentTree* root) {
        if(!root || end < root->start || start > root->end) return -1 ;
        if (start <= root->start && end >= root->end) {
            return root->min ;
        }
        int leftMin = query(heights , start , end , root->left) ;
        int rightMin = query(heights , start , end , root->right) ; 
        if(leftMin == -1)   return rightMin ;
        if(rightMin == -1)  return leftMin ; 
        return heights[leftMin] < heights[rightMin] ? leftMin : rightMin ; 
    }
    //calculates the maximum possible area in the histogram between indexes start and end
    int maxAreaInThisSegment(vector<int> &heights , int start , int end , SegmentTree *root) {
        if(start > end) {
            return -1 ;
        } 
        if(start == end) {
            return heights[start] ;
        }
        int wholeMin = query(heights , start , end , root) ; 
        return max({heights[wholeMin] * (end - start + 1) , maxAreaInThisSegment(heights , start , wholeMin - 1 , root) , maxAreaInThisSegment(heights , wholeMin + 1 , end , root)}) ;
    }
};