class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n =  nums.size();
        vector<int> sorted_arr ,ans(n);

        for(int i=n-1 ;i>=0 ; i--)
        {
            auto it = lower_bound(sorted_arr.begin(),sorted_arr.end(),nums[i]);
            ans[i] = it - sorted_arr.begin();
            sorted_arr.insert(it,nums[i]);
        }

        return ans;
    }
};