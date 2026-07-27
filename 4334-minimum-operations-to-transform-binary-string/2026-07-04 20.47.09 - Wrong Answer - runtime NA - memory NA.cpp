class Solution {
public:
    int minOperations(string s1, string s2) {
        if(s1 == s2){
            return 0;
        }
        int res =  0;
        for(int i = 0; i < s1.size();  i++){
            int count = 0;
            while(s1[i] != s2[i]){ 
                if(s1[i] == '0'){
                    s1[i] = '1';
                    res++ ;
                }
                if(s1[i] == '1' && s1[i+1] == '1'){
                    s1[i] = '0';
                    s1[i+1] = '0';
                    res++;
                }
                count ++;
                if(count >= s1.size()){
                    break;
                }
            } 
            if(s1 != s2){
                return -1;
            }
        }
        return res;
    }
};