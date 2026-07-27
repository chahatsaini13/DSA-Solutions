class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int res = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n-k; i++){
            for(int j = i+k; j < n; j++){
                int maxVal = nums[i] + nums[j];
                res = max(res,maxVal);
            }
        }
        return res;
    }
};