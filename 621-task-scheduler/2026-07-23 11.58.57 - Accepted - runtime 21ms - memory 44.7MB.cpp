class Solution {
public:
    struct cmp{
        bool operator()(pair<int,char>& a, pair<int,char>& b){
            if(a.first != b.first){
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };

    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> f;
        priority_queue<pair<int,char>,
                       vector<pair<int,char>>,
                       cmp> pq;

        queue<pair<pair<int,char>,int>> q;

        for(char c : tasks)
            f[c]++;

        for(auto i : f)
            pq.push({i.second, i.first});

        int time = 0;

        while(!pq.empty() || !q.empty()) {

            time++;

            if(!pq.empty()) {

                auto p = pq.top();
                pq.pop();

                p.first--;

                if(p.first > 0)
                    q.push({p, time + n});
            }

            if(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};