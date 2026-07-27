class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        string res = "";
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(st.empty() || st.top().first != c){
                st.push({c,1});
                continue; 
            }
            if(st.top().first == c){
                if(st.top().second < (k-1)){
                    st.top().second++;
                }
                else{
                    st.pop();
                    continue;
                }
            }
        }
        while(!st.empty()){
            pair<char,int> p = st.top(); 
            while(p.second--){
                res.push_back(p.first);
            }
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};