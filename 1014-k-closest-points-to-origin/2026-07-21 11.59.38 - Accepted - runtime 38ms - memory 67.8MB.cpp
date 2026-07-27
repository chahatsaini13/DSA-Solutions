class Solution {
public:
    struct cmp{
        bool operator()(pair<int, pair<int,int>>& a, pair<int, pair<int,int>>& b){
            if(a.first != b.first){
                return a.first < b.first; // min
            }
            return a.second < b.second; // max
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue <pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, cmp> pq;

        for(auto &p : points){
            int x = p[0];
            int y = p[1];

            int d = x*x + y*y;

            pq.push({d, {x, y}});

            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return res;
    }
};