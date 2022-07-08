class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size() ; 
        int low = -1 , high = m * n ;
        bool found = false ;
        while (!found && high - low > 1) {
            int mid = low + ((high - low) >> 1) ; 
            if (matrix[mid / m][mid % m] < target) {
                low = mid ;
            } else if (matrix[mid / m][mid % m] > target) {
                high = mid ; 
            } else {
                found = true ; 
            }
        }
        return found ;
    }
};