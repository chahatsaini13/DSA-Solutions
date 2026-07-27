class Solution {
public:
    vector<string> generate(int open, int close, int n, string & temp, vector<string> &res){
        if(open == n && close == n){
            res.push_back(temp);
            return res;
        }
        if(open < n){
            temp.push_back('(');
            generate(open+1, close, n, temp, res);
            temp.pop_back();
        }
        if(close < open){
            temp.push_back(')');
            generate(open, close+1, n, temp, res);
            temp.pop_back();
        }

        return res;
    }

    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        vector<string> res;
        string temp = "";

        return generate(open, close, n, temp, res);
    }
};