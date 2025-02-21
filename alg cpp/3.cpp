class Solution {
    public:
        int maxAscendingSum(vector<int>& nums) {
            int maxSum = nums[0];
            int currentSum = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] > nums[i - 1]) {
                    // Continue the ascending subarray
                    currentSum += nums[i];
                } else {
                    // Update maxSum if needed, then restart currentSum
                    maxSum = max(maxSum, currentSum);
                    currentSum = nums[i];
                }
            }
            // Final check for the last ascending subarray
            maxSum = max(maxSum, currentSum);
            return maxSum;
        }
    };
    