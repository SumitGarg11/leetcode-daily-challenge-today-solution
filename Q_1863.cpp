class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int totalSum = 0;

        for (int i: nums) {
            totalSum |= i;
        }
        return totalSum << (nums.size() - 1);
    }
};
