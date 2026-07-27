class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> need;
        unordered_map<char,int> have;
        int minValue = INT_MAX;
        {
            need['b'] = 1;
            need['a'] = 1;
            need['l'] = 2;
            need['o'] = 2;
            need['n'] = 1;
        }
        for(int i = 0; i < text.size(); i++){
            have[text[i]]++;
        }
        for(auto c: need){
            if (have.find(c.first) == have.end()){
                return 0;
            }
            have[c.first] /= c.second;
            minValue = min(minValue, have[c.first]);

        }      
        
        return minValue;
        
    }
};