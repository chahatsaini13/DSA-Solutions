class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> s;
        vector<int> ans;
        int n = grid.size();

        for(int i = 0; i < n; i++){
            for(int j=0; j<n; j++){
                if(s.find(grid[i][j]) != s.end()){
                    ans.push_back(grid[i][j]);
                }

                s.insert(grid[i][j]);
            }
        }

        for(int k=1; k<=(n*n); k++){
            if(s.find(k) == s.end()){
                ans.push_back(k);
                break;
            }
        }

        return ans;
    
    }
};