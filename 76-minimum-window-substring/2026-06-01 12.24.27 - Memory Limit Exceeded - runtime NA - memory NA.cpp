class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        int l = 0, h = 0;
        string res = "";

        unordered_map<char, int> f;

        for (int i = 0; i < n; i++) {
            f[t[i]]++;
        }

        int count = n;

        while (h < m) {
            if (f[s[h]] > 0) {
                count--;
            }

            f[s[h]]--;

            while (count == 0) {
                if (res.empty() || (h - l + 1) < res.size()) {
                    res = s.substr(l, h - l + 1);
                }

                f[s[l]]++;

                if (f[s[l]] > 0) {
                    count++;
                }

                l++;
            }

            h++;
        }

        return res;
    }
};