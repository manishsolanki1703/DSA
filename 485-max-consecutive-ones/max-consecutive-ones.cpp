class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size() , i=0 , j=0;
        int ans = 0;

        while(i<n && j<n)
        {
            while(i<n && nums[i]==0) i++;
            j = i;
            while(j<n && nums[j]==1) j++;
            ans = max(ans , j-i);
            i = j;
        }

        return ans;
    }
};