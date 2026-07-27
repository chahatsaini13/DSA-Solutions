class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int min_end = nums[0];
        int max_end = nums[0];

        for(int i=1; i<nums.size(); i++){
            int v1 = min_end * nums[i];
            int v2 = max_end * nums[i];
            int v3 = nums[i];

            min_end = min(v1,min(v2,v3));
            max_end = max(v1, max(v2,v3));
            ans = max(ans,max(min_end, max_end));
        }

        return ans;
    }
};