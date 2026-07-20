class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> consecutives; // consecutives[num] = length of longest consec nums in nums at borders
        int longest = 0;

        for (int num : nums){
            if (!consecutives[num]) {
                int prevNum = num-1, nextNum = num+1;
                consecutives[num] = consecutives[prevNum] + 1 + consecutives[nextNum];
                consecutives[num - consecutives[prevNum]] = consecutives[num];
                consecutives[num + consecutives[nextNum]] = consecutives[num];
                if (consecutives[num] > longest)
                    longest = consecutives[num];
            }
        }
        return longest;
    }
};
