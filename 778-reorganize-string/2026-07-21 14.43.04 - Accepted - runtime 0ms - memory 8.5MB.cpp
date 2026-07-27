class Solution {
public:
    struct cmp{
        bool operator() (pair<int,char> &a, pair<int,char> &b) {
            if(a.first != b.first){
                return a.first < b.first; //max
            }
            return a.second > b.second; //min
        }
    };

    string reorganizeString(string s) {
        unordered_map<char, int> f;
        priority_queue<pair<int, char>, vector<pair<int,char>>, cmp> pq;
        string res = "";
        int seat = 0;

        for(int i = 0; i< s.size(); i++){
            f[s[i]]++;
        }

        for(auto i: f){
            char ele = i.first;
            int freq = i.second;
            pair<int, char> curr = {i.second, i.first};
            pq.push(curr);
        }

        while(!pq.empty()){
            pair<int, char> p = pq.top();
            pq.pop();
            if(res.empty() || res.back() != p.second){
                res.push_back(p.second);
                p.first --;
                if(p.first > 0){
                    pq.push(p);
                }
                seat++;
            }
            else{
                if(pq.empty()){
                    return "";
                }
                pair<int,char> p1 = pq.top();
                pq.pop();
                res.push_back(p1.second);
                p1.first--;
                if(p1.first > 0){
                    pq.push(p1);
                }
                pq.push(p);
                seat++;
            }
        }

        return res;
    }
};