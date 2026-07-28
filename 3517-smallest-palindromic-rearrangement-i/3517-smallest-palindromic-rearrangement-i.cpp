class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> f;
        string left = "";
        string mid = "";

        for(int i = 0; i < s.size(); i++){
            f[s[i]]++;
        }

        for(auto i : f){
            left += string(i.second / 2, i.first);
            if(i.second % 2 == 1){
                mid = i.first;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        string res = left + mid + right;

        return res;
    }
};