class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = nums[0];
        int best_ending = nums[0];

        for(int i=1; i<nums.size(); i++){
            int v1 = best_ending + nums[i];
            int v2 = nums[i];

            best_ending = max(v1,v2);
            ans = max(best_ending,ans);
        }

        return ans;
    }

    int minSum(vector<int>& a) {
        int ans = a[0];
        int best_end = a[0];
        
        for(int i=1; i<a.size(); i++){
            int v1 = best_end + a[i];
            int v2 = a[i];
            
            best_end = min(v1,v2);
            ans = min(ans, best_end);
        }
        
        return ans;
        
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
        }

        int v1 = maxSum(nums);
        int v2 = sum - minSum(nums);

        if (v1 < 0) {
            return v1;
        }
        
        int ans = max(v1,v2);

        return ans;
    }
};