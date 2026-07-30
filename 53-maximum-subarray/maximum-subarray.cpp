class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0] , sum = 0;

        for(auto it : nums)
        {
            sum = max(it , sum+it);
            max_sum = max(max_sum , sum);
        }

        return max_sum;
    }
};