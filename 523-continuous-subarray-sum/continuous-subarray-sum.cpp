class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        int prefix = 0;
        for(int r=0 ; r<nums.size() ; r++)
        {
            prefix += nums[r];
            if((prefix%k ==0 && r>=1) || (freq.count(prefix%k) && r-freq[prefix%k]>1)) return true;

            if (!freq.count(prefix%k)) freq[prefix%k] = r;
        }

        return false;
    }
};