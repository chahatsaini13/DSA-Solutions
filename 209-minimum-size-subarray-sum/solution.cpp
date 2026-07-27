class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = 0;
        int sum = 0;
        int res = INT_MAX;

        while(h<n){
            sum = sum + nums[h];
            
            while(sum >= target){
                int len = h - l + 1;
                res = min(res, len);
                sum = sum - nums[l];
                l++ ;
            }

            h++ ;
        }

        if(res == INT_MAX) {
            return 0;
        }else {
            return res;
        }
    }
};