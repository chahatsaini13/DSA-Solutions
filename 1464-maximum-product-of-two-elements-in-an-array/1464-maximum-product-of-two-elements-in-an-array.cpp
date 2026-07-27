class Solution {
public:
    int max(vector<int>& nums){
        int max = INT_MIN;
        int maxidx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max){
                max = nums[i];
                maxidx = i;
            }
        }
        return maxidx;
    }
    int maxProduct(vector<int>& nums) {
        int i1 = max(nums);  //idx of first max no
        int max1 = nums[i1]; //first max no

        nums[i1] = 0; // replaced first max with 0 to find second max

        int i2 = max(nums);
        int max2 = nums[i2];

        return ((max1-1) * (max2-1));
        
    }
};