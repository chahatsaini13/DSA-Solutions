class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));;
        int srow = 0, erow = n-1, scol = 0, ecol = n-1;
        int x = 1;
        while(srow <= erow && scol <= ecol){
            for(int j=scol; j<=ecol; j++){
                mat[srow][j] = x++;
            }

            //right
            for(int i=srow+1; i<=erow; i++){
                mat[i][ecol] = x++;
            }

            //bottom
            for(int j=ecol-1; j>=scol; j--){
                if(srow == erow){
                    break;
                }
                mat[erow][j] = x++;
            }

            //left
            for(int i=erow-1; i>=srow+1; i--){
                if(scol == ecol){
                    break;
                }
                mat[i][scol] = x++;
            }

            srow++ ; erow--; scol++; ecol--;
        }

        return mat;

    }
};