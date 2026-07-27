class Solution {
public:
    int num(int m, int n, int guess) {
        int count = 0;

        for (int i = 1; i <= m; i++) {
            count += min(guess / i, n);
        }

        return count;
    }

    int findKthNumber(int m, int n, int k) {
        int l = 1, h = m*n;
        int res = -1;
        while(l <= h){
            int guess = (l+h)/2;
            int no = num(m, n, guess);
            if(no < k){
                l = guess + 1;
            }
            else{
                res = guess;
                h = guess - 1;
            }
        }

        return res;
    }
};