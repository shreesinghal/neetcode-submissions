class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts; // counts[a] = b where a appears a times in nums
        vector<vector<int>> frequency(nums.size() +1); // frequency[i] = lst where every item in lst appears i times in nums

        // populate counts
        for (int number: nums) 
            counts[number]++;

        // populate frequency
        for (auto couple : counts) {
            frequency[couple.second].push_back(couple.first);
        }

        vector<int> topK = {};

        for (int i = frequency.size() - 1; i >= 0 && k > 0; i--) {
            if (frequency.size())
                for (int j = frequency[i].size() - 1; j >= 0 && k > 0; j--) {
                    if (frequency[i].size()) {    
                        if (k) {
                            topK.push_back(frequency[i][j]);
                            k--;
                        }
                        else {
                            return topK;
                        }
                    }
                }
        }

        return topK;
    }
};
