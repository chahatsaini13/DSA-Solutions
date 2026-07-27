class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0;
        int h = n - 1;
        int res = 0;
        
        while(l <= h){
            int guess = (l + h)/2;
            if( citations[guess] >= n - guess){
                res = n - guess;
                h = guess - 1;
            }else{
                l = guess + 1;
            }
        }
        return res;
    }
};