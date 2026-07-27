class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> one;
        unordered_map<char,int> two;
        int m = ransomNote.size();
        int n = magazine.size();
        for(int i = 0; i < m; i++){
            one[ransomNote[i]]++;
        }
        for(int i = 0; i < n; i++){
            two[magazine[i]]++;
        }

        if(m>=n){
            for(int i = 0; i < m; i++){
                if(one[ransomNote[i]] >= two[ransomNote[i]]){
                    return true;
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if(one[magazine[i]] =< two[magazine[i]]){
                    return true;
                }
            }
        }
        return false;
    }
};