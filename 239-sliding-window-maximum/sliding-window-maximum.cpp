class Solution {
    vector<int> NGE(const vector<int> &arr)
    {
        int n=arr.size();
        stack<pair<int,int>> st;
        vector<int> ans(n,n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top().first<arr[i])
            {
                ans[st.top().second]=i;
                st.pop();
            }
            st.push({arr[i],i});
        }
        return ans;
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=-1 , curr=0 , r=l+k , n=nums.size();
        vector<int> nge = NGE(nums) , ans;

        while(r<n)
        {
            if(curr==l) curr++;
            while(nge[curr]<=r) curr=nge[curr];
            ans.push_back(nums[curr]);
            l++;
            r++;
        }

        return ans;
    }
};