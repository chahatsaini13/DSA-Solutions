class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        unordered_map<char, int> f;

        for (char c : t) {
            f[c]++;
        }

        int count = n;
        int l = 0, h = 0;

        int start = -1;
        int minLen = INT_MAX;

        while (h < m) {
            if (f[s[h]] > 0) {
                count--;
            }

            f[s[h]]--;

            while (count == 0) {
                if (h - l + 1 < minLen) {
                    minLen = h - l + 1;
                    start = l;
                }

                f[s[l]]++;

                if (f[s[l]] > 0) {
                    count++;
                }

                l++;
            }

            h++;
        }

        return start == -1 ? "" : s.substr(start, minLen);
    }
};