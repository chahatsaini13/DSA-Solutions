class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;

        if(n == 3){
            for(int i = 0; i < 3; i++){
                prod *= nums[i];
            }
            return prod;
        }
        
        sort(nums.begin(), nums.end());

        int prod1 = nums[n-1] * nums[n-2] * nums[n-3];
        int prod2 = nums[0] * nums[1] * nums[n-1];

        return max(prod1, prod2);
    }
};