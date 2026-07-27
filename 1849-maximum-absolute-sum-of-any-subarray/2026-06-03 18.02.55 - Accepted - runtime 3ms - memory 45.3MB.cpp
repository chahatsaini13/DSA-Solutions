class Solution {
public:
    int maxSum(vector<int>& nums){
        int best = nums[0];
        int ans = nums[0];

        for(int i = 1; i<nums.size(); i++){
            best = max(best+nums[i], nums[i]);
            ans = max(ans, best);
        }

        return ans;
    }

    int minSum(vector<int>& nums){
        int best = nums[0];
        int ans = nums[0];

        for(int i = 1; i<nums.size(); i++){
            best = min(best+nums[i], nums[i]);
            ans = min(ans, best);
        }

        return ans;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = maxSum(nums);
        int mini = minSum(nums);

        int ans = max(maxi, abs(mini));
        return ans;
    }
};