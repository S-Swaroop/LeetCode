class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size() ; 
        if (n == 1) {//only one element so we are already at the last index
            return true ; 
        }
        if (a[0] == 0) { //base case if no jumps possible
            return false ; 
        }
        for (int i = 1 ; i < n - 1 ; i++) {
            a[i] = max(a[i] , a[i - 1] - 1) ;//comparing if its better to take the jump now or continue the last jump
            if (a[i] == 0) return false ; 
        }
        return true ; 
    }
};