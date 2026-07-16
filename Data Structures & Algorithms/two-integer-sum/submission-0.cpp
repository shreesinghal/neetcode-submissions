class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indicies;     // indicies[num] = index
        for (int i = 0; i < nums.size(); i++) {
            indicies[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (indicies.count(diff) && indicies[diff] != i) {
                return {i, indicies[diff]};
            }
        }

        return {};
    }
};
