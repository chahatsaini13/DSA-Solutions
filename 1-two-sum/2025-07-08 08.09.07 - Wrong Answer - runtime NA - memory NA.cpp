class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int i = 0;
        int j = nums.size() - 1;
        
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum < target){
                i++;
            }
            else if(sum > target){
                j--;
            }
            else{
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
        return {};
    }
};