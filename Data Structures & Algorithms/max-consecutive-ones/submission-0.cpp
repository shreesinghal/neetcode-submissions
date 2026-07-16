class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecOne = 0;
        int currConsecOne = 0;

        for (auto bit : nums) {
            if (bit) {
                currConsecOne++;
            }
            if (maxConsecOne < currConsecOne) {
                    maxConsecOne = currConsecOne;
            }
            if (!bit) {
                
                currConsecOne = 0;
            }
        }
        
        return maxConsecOne;
    }
};