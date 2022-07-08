class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums , target , getPivot(nums)) ; 
    }
private: 
    int getPivot (vector<int> &nums) {
        int n = nums.size() , low = 0 , high = n - 1 ; 
        while (high - low >= 1) {
            int mid = low + (high - low) / 2 ; 
            if (nums[mid] > nums[high]) {
                low = mid + 1 ; 
            } else {
                high = mid ; 
            }
        }
        return low ;
    }
    int binarySearch (vector<int> &nums , int target , int pivot) {
        int n = nums.size() , low = -1 , high = n ; 
        while (high - low > 1) {
            int mid = low + (high - low) / 2 ; 
            int realMid = (mid + pivot) % n ;
            if (nums[realMid] < target) {
                low = mid ; 
            } else if (nums[realMid] > target) {
                high = mid ; 
            } else {
                return realMid ;
            }
        }
        return -1 ; 
    }
};