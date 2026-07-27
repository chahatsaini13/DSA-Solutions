class Solution {
public:
    int reverse(int n) {
      int rev_no = 0;

      while(n != 0){
        int digit = n % 10;
        rev_no = rev_no *10 + digit;
        n = n/10; 
      }  

      return rev_no;
    }
};