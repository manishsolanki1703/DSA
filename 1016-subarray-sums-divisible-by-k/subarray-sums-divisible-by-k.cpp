class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0]++;

        int prefix = 0 ,  ans = 0;
        for(int i=0 ; i<nums.size() ; i++)
        {
            prefix += nums[i];
            int u = ((prefix % k) + k) %k;
            if(freq.count(u)) ans += freq[u];

            freq[u]++;
        }

        for(auto it : freq) cout<<it.first<<" "<<it.second<<endl;
        return ans;
    }
};