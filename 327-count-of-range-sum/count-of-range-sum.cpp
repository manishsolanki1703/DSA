class Solution {
    int lower , upper ;
    int MergeSort(vector<long long>& arr , int l , int r )
    {
        if(r-l <= 1) return 0;

        int mid = (l+r) >> 1 , count = 0;
        count += MergeSort(arr , l , mid);
        count += MergeSort(arr , mid , r);

        int low = mid , high = mid;
        for(int i=l ; i<mid ;i++)
        {
            while(low<r && (arr[low]-arr[i] < lower)) low++;
            while(high<r && (arr[high]-arr[i] <= upper)) high++;

            count += high - low ;
        }

        vector<long long> temp;
        int i=l , j=mid ;
        while(i<mid && j<r)
        {
            if(arr[i]<=arr[j]) temp.push_back(arr[i++]);
            else temp.push_back(arr[j++]);
        }

        while(i<mid) temp.push_back(arr[i++]);
        while(j<r) temp.push_back(arr[j++]);

        for(int k=l ; k<r ;k++) arr[k] = temp[k-l];
        return count;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower;
        this->upper = upper;

        int n = nums.size();
        vector<long long> prefix_sum(n+1,0);
        for(int i=0 ; i<n ; i++) prefix_sum[i+1] = prefix_sum[i] + nums[i];

        return MergeSort(prefix_sum , 0 , n+1); 
    }
};