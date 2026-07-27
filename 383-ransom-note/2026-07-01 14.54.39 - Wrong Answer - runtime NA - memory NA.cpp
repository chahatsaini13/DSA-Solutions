class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> one;
        unordered_map<char,int> two;
        for(int i = 0; i < ransomNote.size(); i++){
            one[ransomNote[i]]++;
        }
        for(int i = 0; i < magazine.size(); i++){
            two[magazine[i]]++;
        }
        for(int i = 0; i < ransomNote.size(); i++){
            if(one[ransomNote[i]] == two[ransomNote[i]]){
                return true;
            }
        }

        return false;
    }
};