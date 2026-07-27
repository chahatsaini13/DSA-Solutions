class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = nums[n/2];
        for(int i = 0; i <= (n/2) - 1; i++){
            if(nums[i] == mid){
                return false;
            }
        }
        for(int i = (n/2) + 1; i < n; i++){
            if(nums[i] == mid){
                return false;
            }
        }
        return true;
    }
};