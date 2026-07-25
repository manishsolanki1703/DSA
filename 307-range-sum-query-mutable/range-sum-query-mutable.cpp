class NumArray {
    int n;
    vector<int> arr , seg;
    void _Build (int index , int l , int r){
        if (l == r)
        {
            seg[index] = arr[l];
            return ;
        }

        int mid = (l + r) >> 1;
        _Build((index<<1) + 1 , l , mid);
        _Build((index<<1) + 2 , mid+1 , r);

        seg[index] = seg[(index<<1) + 1] + seg[(index<<1) + 2];
        return ;
    }

    void _update (int index , int l , int r ,int i){
        if (l == r)
        {
            seg[index] = arr[l];
            return ;
        }

        int mid = (l + r) >> 1;
        if (i <= mid) _update((index<<1) + 1 , l , mid , i);
        else _update((index<<1) + 2 , mid+1 , r , i);

        seg[index] = seg[(index<<1) + 1] + seg[(index<<1) + 2];
        return ;
    }

    int _query(int index , int l , int r , int L , int R){
        if (l>R || r<L) return 0;
        if (l>=L && r<=R) return seg[index];

        int mid = (l + r) >> 1;
        int left = _query((index<<1) + 1 , l , mid , L , R);
        int right = _query((index<<1) + 2 , mid+1 , r , L , R);

        return left+right ;
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        seg.resize(n << 2);
        _Build(0 , 0 , n-1);

        for(auto it : arr) cout<<it<<" ";
        cout<<endl;

        for(auto it : seg) cout<<it<<" ";
        cout<<endl;
    }
    
    void update(int index, int val) {
        arr[index] = val;
        _update(0 , 0 , n-1 , index);
    }
    
    int sumRange(int left, int right) {
        return _query(0 , 0 , n-1 , left , right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */