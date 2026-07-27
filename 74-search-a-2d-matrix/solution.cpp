class Solution {
public:
    bool bsearch(vector<vector<int>>& mat, int target, int row){
        int n = mat[0].size();
        int st = 0, end = n-1;

        while(st<=end){
            int mid = st + (end-st)/2;
            if(target == mat[row][mid]){
                return true;
            }else if( target < mat[row][mid]){
                end = mid-1;
            }else{
                st = mid+1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& mat, int target){
        int m = mat.size(), n = mat[0].size();

        int sRow = 0, eRow = m-1;

        while(sRow <= eRow){
            int mRow = sRow + (eRow -sRow)/2;
            if(target >= mat[mRow][0] && target <= mat[mRow][n-1]){
                return bsearch(mat, target, mRow);
            }else if(target <= mat[mRow][0]){
                eRow = mRow-1;
            }else{
                sRow = mRow+1;
            }
        }
        return false;
    }
};