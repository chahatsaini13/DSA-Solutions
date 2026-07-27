class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>f;
        int len = 0;

        for(int i = 0; i < s.size(); i++){
            f[s[i]]++;
        }

        bool odd = false;

        for(auto i : f){
            if (i.second % 2 == 0){
                len = len + i.second;
            }
            else{
                odd = true;
            }
        }

        if(odd == false){
            return len;
        }
        else{
            for(auto i : f){
                if(i.second % 2 == 1){
                    len = len + i.second - 1;
                }
            }
            len++;
        }

        return len;

    }
};