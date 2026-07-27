class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        int s = a.size();
        vector<int> neg;
        vector<int> pos;
        for(int i=0; i<s; i++) {
            if(a[i] < 0) 
                neg.push_back(a[i]);
            else
                pos.push_back(a[i]);
        }
        if(neg.size() ==  0) {
            for(int j=0; j < pos.size(); j++) {
                pos[j] = pos[j] * pos[j];
            }
            return pos;
        }
        if(pos.size() == 0) {
            for(int j=0; j < neg.size(); j++) {
                neg[j] = neg[j] * neg[j];
            }
            reverse(neg.begin(), neg.end());
            return neg;
        }

        int x = 0, y = 0;
        int idx = 0;
        int n = neg.size();
        int p = pos.size();
        vector<int> res(p+n);

        for(int j=0; j<n; j++) {
            neg[j] = neg[j] * neg[j];
        }
        reverse(neg.begin(), neg.end());
        
        for(int j=0; j<p; j++) {
            pos[j] = pos[j] * pos[j];
        }

        while(x<n && y<p) {
            if(neg[x] < pos[y]){
                res[idx] = neg[x];
                idx++;
                x++;
            }
            else {
                res[idx] = pos[y];
                idx++;
                y++;
            }
        }

        while(x<n) {
            res[idx] = neg[x];
            idx++;
            x++;
        }

        while(y<p) {
            res[idx] = pos[y];
            idx++;
            y++;
        }

        return res;
    }
};