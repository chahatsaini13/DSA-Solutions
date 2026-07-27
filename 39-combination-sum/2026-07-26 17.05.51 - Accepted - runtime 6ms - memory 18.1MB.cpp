class Solution {
public:
    void combo(vector<int>& candidates, int idx, int n, int sum, vector<vector<int>>& res, vector<int>& diary, int target) {
        if(idx == n){
            if(sum == target){
                res.push_back(diary);
            } 
            return;
        }

        combo(candidates, idx+1, n, sum, res, diary, target);

        if(candidates[idx] + sum <= target){
            diary.push_back(candidates[idx]);
            sum += candidates[idx];
            combo(candidates, idx, n, sum, res, diary, target);
            diary.pop_back();
            sum -= candidates[idx];
        }

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum = 0, idx = 0;
        vector<vector<int>> res;
        vector<int> diary;

        combo(candidates, idx, n, sum, res, diary, target);

        return res;
    }
};