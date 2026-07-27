class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> one;
        unordered_map<char,int> two;
        int m = ransomNote.size();
        int n = magazine.size();
        for(char c : ransomNote){
            one[c]++;
        }
         for(char c : magazine){
            two[c]++;
        }
        for(auto it : one){

            if(two[it.first] < it.second){
                return false;
            }
        }
        return true;
    }
};