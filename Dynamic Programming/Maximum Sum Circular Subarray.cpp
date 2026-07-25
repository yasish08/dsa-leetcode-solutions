class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int sum = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];

            sum += nums[i];
            maxi = max(maxi, sum);

            if (sum < 0)
                sum = 0;
        }

        if (maxi < 0)
            return maxi;

        sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            mini = min(mini, sum);

            if (sum > 0)
                sum = 0;
        }

        return max(maxi, total - mini);
    }
};