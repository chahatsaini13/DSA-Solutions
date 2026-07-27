class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int res = 0;
        int sum = 0; 

        for(int high = 0; high < n; high++){
            sum = sum + nums[high];
            int len = high - low + 1;
            while((len - sum) > k){
                sum = sum - nums[low];
                low++ ;
                len = high - low + 1;
            }
            len = high - low + 1;
            res = max(len, res);
        }

        return res;

    }
};