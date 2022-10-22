class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> set;
        for(int i = 0; i < nums.size(); i++)
        {
            if(set.count(nums[i]))
            {
                int diff = abs(set[nums[i]] - i);
                if (diff <= k)
                {
                    return true;
                }
                // set[nums[i]] = i;
            }
            set[nums[i]] = i;
        }
        return false;
    }
};