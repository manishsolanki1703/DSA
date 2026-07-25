class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<int> pq{0} ;

        vector<pair<int,int>> points ;

        for(auto b : buildings)
        {
            points.push_back({b[0],-b[2]});
            points.push_back({b[1],b[2]});
        }

        sort(points.begin(),points.end());

        int OnGoingHeight = 0;

        for(int i = 0; i < points.size(); i++){
            int CurrentPoint = points[i].first;
            int HeightAtCurrentPoint = points[i].second;

            if(HeightAtCurrentPoint < 0)
            {
                pq.insert(-HeightAtCurrentPoint);
            }
            else
            {
                pq.erase(pq.find(HeightAtCurrentPoint));
            }

            auto pqTop = *pq.rbegin();
            if(OnGoingHeight != pqTop){
                OnGoingHeight = pqTop;
                ans.push_back({CurrentPoint,OnGoingHeight});
            }
        }

        return ans;
    }
};