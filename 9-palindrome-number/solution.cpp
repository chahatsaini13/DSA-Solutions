class Solution {
public:
    int revNum(int n){
        int rev_no = 0;

        while(n != 0){
            int digit = n % 10;
            if(rev_no > INT_MAX/10 || rev_no < INT_MIN/10){
                return 0;
            }
            rev_no = rev_no *10 + digit;
            n = n/10; 
        }  

        return rev_no;
    }

    bool isPalindrome(int n) {
        if(n < 0) return false;
        if(revNum(n) == n) return true;
        return false;
    }
};