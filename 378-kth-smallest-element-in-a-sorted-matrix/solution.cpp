class Solution {
public:
    int num(vector<vector<int>>& mat, int guess){
        int r = mat.size(), c = mat[0].size();
        int row = r - 1, col = 0; 
        int count = 0;
        while(row >= 0 && col < c){
            if(mat[row][col] <= guess){
                count = count + row + 1;
                col ++;
            }
            else{
                row --;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& mat, int k) {
        int r = mat.size(), c = mat[0].size();
        int l = mat[0][0], h = mat[r-1][c-1];
        int res = -1;
        while(l <= h){
            int guess = (l+h)/2;
            int no = num(mat, guess);
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