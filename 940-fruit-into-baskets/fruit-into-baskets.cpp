class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;
        int l=0 , n=fruits.size() ,ans=0;

        for(int r=0 ; r<n;r++)
        {
            freq[fruits[r]]++;
            while(freq.size()>2)
            {
                freq[fruits[l]]--;
                if(freq[fruits[l]] == 0) freq.erase(fruits[l]);
                l++;
            }

            ans = max(ans,r-l+1);
        }

        return ans;
    }
};