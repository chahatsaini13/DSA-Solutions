class Solution {
public:
    void combo(vector<int>& nums, vector<bool>& used, vector<vector<int>>& res, vector<int>& temp) {
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true){
                continue;
            }

            used[i] = true;
            temp.push_back(nums[i]);

            combo(nums,used,res,temp);

            temp.pop_back();
            used[i] = false;
        }

        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<vector<int>> res;
        vector<int> temp;

        combo(nums,used,res,temp);

        return res;
    }
};