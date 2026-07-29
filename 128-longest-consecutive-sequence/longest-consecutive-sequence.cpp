class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()) , nums.end());

        int i=0 , j=1 , ans = 1 , n=nums.size();
        while(j<n)
        {
            while(j<n && nums[j] - nums[j-1] == 1) j++;
            ans = max(ans,j-i);
            i = j;
            j++;
        }
        return ans;
    }
};