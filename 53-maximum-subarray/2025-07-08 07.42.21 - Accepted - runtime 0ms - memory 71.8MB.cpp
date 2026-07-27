class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs = 0;
        int max_sum = INT_MIN;

        for(int val : nums){
            cs = cs + val;
            max_sum = max(cs, max_sum);
            if(cs < 0){
                cs = 0;
            }
        }

        return max_sum;
    }
};