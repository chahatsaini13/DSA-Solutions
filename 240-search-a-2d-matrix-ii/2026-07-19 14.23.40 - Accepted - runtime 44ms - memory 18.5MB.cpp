class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int r = mat.size(), c = mat[0].size();
        int row = r - 1, col = 0;
        
        while(row >= 0 && col < c){
            if(mat[row][col] > target){
                row --;
            }
            else if(mat[row][col] < target){
                col ++;
            }
            else{
                return true;
            }
        }

        return false;
    }
};