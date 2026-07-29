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

    class Fenwick {
        vector<int> bit;
        int n;
    
    public :
        Fenwick (int n){
            this->n = n;
            bit.assign(n+1,0);
        }

        void update(int idx , int val)
        {
            while (idx<=n)
            {
                bit[idx]+=val;
                idx += idx & (-idx);
            }
        }

        int query(int idx)
        {
            int sum = 0;
            while (idx>0)
            {
                sum += bit[idx];
                idx-= idx & (-idx);
            }
            return sum;
        }
    };

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // this->lower = lower;
        // this->upper = upper;

        int n = nums.size();
        vector<long long> prefix_sum(n+1,0);
        for(int i=0 ; i<n ; i++) prefix_sum[i+1] = prefix_sum[i] + nums[i];

        // return MergeSort(prefix_sum , 0 , n+1); 

        vector<long long> arr;
        for(auto it : prefix_sum)
        {
            arr.push_back(it); 
            arr.push_back(it - lower); 
            arr.push_back(it-upper);
        }
        
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()) , arr.end());
        Fenwick ft(arr.size());

        long long ans = 0;

        for(auto it : prefix_sum)
        {
            int left = lower_bound(arr.begin(),arr.end(),it - upper) - arr.begin() + 1;
            int right = upper_bound(arr.begin(),arr.end(),it - lower) - arr.begin();

            ans += ft.query(right) - ft.query(left-1);

            int idx = lower_bound(arr.begin(),arr.end(),it) - arr.begin() + 1;

            ft.update(idx , 1);
        }

        return ans;
    }
};