class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target){
        int r = mat.size();
        int c = mat[0].size();
        int l = 0, h = r*c - 1;

        while(l <= h){
            int guess = (l+h)/2;
            int row = guess / c;
            int col = guess % c;

            if(mat[row][col] < target){
                l = guess + 1;
            }
            else if(mat[row][col] > target){
                h = guess - 1;
            }
            else{
                return true;
            }
        }

        return false;
        
    }
};