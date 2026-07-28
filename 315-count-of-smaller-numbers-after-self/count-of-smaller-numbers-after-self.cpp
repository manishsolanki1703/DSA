class Solution {
    vector<int> ans;
    void MergeSort(vector<pair<int,int>>& arr , int l , int r)
    {
        if (l>=r) return;

        int mid = (l+r) >> 1;
        MergeSort(arr , l , mid);
        MergeSort(arr , mid+1 , r);

        int i = l , j = mid+1 , RightCounted = 0;
        vector<pair<int,int>> temp;
        while(i<=mid && j<=r)
        {
            if(arr[j].first < arr[i].first)
            {
                temp.push_back(arr[j++]);
                RightCounted++;
            }
            else
            {
                temp.push_back(arr[i]);
                ans[arr[i++].second] += RightCounted;
            }
        }

        while (i<=mid)
        {
            temp.push_back(arr[i]);
            ans[arr[i++].second] += RightCounted;
        }

        while (j<=r)
        {
            temp.push_back(arr[j++]);
        }

        for(int k=l ; k<=r ; k++)
        {
            arr[k] = temp[k-l];
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        // int n =  nums.size();
        // vector<int> sorted_arr ,ans(n);

        // for(int i=n-1 ;i>=0 ; i--)
        // {
        //     auto it = lower_bound(sorted_arr.begin(),sorted_arr.end(),nums[i]);
        //     ans[i] = it - sorted_arr.begin();
        //     sorted_arr.insert(it,nums[i]);
        // }

        // return ans;

        int n = nums.size();
        vector<pair<int,int>> arr;
        ans.assign(n,0);

        for(int i=0 ; i<n ; i++) arr.push_back({nums[i],i});

        MergeSort(arr,0,n-1);

        return ans;
    }
};