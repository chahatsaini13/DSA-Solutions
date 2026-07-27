class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        string res;
        for(int i = 0; i < s.size(); i++){
            if(stk.empty()){
                stk.push(s[i]);
                continue;
            }

            if(stk.top() == s[i]){
                stk.pop();
                continue;
            }

            stk.push(s[i]);
        }
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return(res);
    }
};