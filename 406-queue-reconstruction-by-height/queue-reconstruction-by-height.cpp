class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> temp = people;

        sort(temp.begin(),temp.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<vector<int>> ans(people.size(),vector<int>(2,-1));

        for(auto it : temp) cout<<it[0]<<" "<<it[1]<<endl;
        cout<<endl;

        for(auto it : temp)
        {
            int count = it[1];
            for(int i=0 ; i<ans.size() ; i++)
            {
                if (count == 0 && ans[i][0] == -1) 
                {
                    ans[i] = it;
                    break;
                }
                if (ans[i][0] == -1) count--;
            }
        }

        return ans;
    }
};