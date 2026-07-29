class Solution {
    int atmost(vector<int>& nums , int k)
    {
        unordered_map<int,int> freq;
        int l=0,n=nums.size(),ans=0;

        for(int r=0 ; r<n ; r++)
        {
            freq[nums[r]]++;

            while(freq.size() > k)
            {
                freq[nums[l]]--;
                if(freq[nums[l]] == 0) freq.erase(nums[l]);
                l++;
            }

            ans += r-l+1;
        }

        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};