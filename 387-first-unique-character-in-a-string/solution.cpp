class Solution {
public:
    int firstUniqChar(string s) {
        int res;
        unordered_map<char,int> f;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            f[c]++;
        }
        for(int i = 0; i < s.size(); i++){
            if(f[s[i]] == 1){
                return i;
            }
        }

        return -1;
        
    }
};