class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>f;
        int len = 1;

        for(int i = 0; i < s.size(); i++){
            f[s[i]]++;
        }

        for(auto i : f){
            if (i.second % 2 == 0){
                len = len + i.second;
            }
        }

        return len;

    }
};