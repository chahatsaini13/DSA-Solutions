class Solution {
public:
    void combo(string &s, int n, int idx, string &temp, vector<string> &res){
        unordered_map<char, string> code;
        code['2'] = "abc";
        code['3'] = "def";
        code['4'] = "ghi";
        code['5'] = "jkl";
        code['6'] = "mno";
        code['7'] = "pqrs";
        code['8'] = "tuv";
        code['9'] = "wxyz";

        if(idx == n){
            res.push_back(temp);
            return;
        }
        string choice = code[s[idx]];
        for(int j = 0; j < choice.size(); j++){
            temp.push_back(choice[j]);
            combo(s, n, idx+1, temp, res);
            temp.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        string temp = "";
        vector<string> res;

        combo(digits, n, 0, temp, res);

        return res;
    }
};