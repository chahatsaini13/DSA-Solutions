class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> res;

        int s1 = newInterval[0];
        int e1 = newInterval[1];

        bool inserted = false;

        for(int i = 0; i < intervals.size(); i++) {

            int s2 = intervals[i][0];
            int e2 = intervals[i][1];

            if(e2 < s1) {
                res.push_back(intervals[i]);
            }

            else if(s2 > e1) {

                if(!inserted) {
                    res.push_back({s1, e1});
                    inserted = true;
                }

                res.push_back(intervals[i]);
            }

            else {
                s1 = min(s1, s2);
                e1 = max(e1, e2);
            }
        }

        if(!inserted) {
            res.push_back({s1, e1});
        }

        return res;
    }
};