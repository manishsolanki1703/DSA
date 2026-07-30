class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0) , suffix(n,0);

        for(int i=1 ; i<n ; i++)
        {
            prefix[i] = prefix[i-1] + nums[i-1];
            suffix[n-1-i] = suffix[n-i]+nums[n-i];
        }

        for(int i=0 ; i<n ; i++)
        {
            if(prefix[i] == suffix[i]) return i;
        }

        return -1;
    }
};