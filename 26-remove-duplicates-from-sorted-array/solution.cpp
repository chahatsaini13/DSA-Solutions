class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low = 0;
        int unique = 1;
        int high = 1;
        while(high < nums.size()) {
            if(nums[high] == nums[high-1]) {
                high++ ;
                continue;
            }

            nums[low + 1] = nums[high];
            low++ ;
            unique++ ;
            high++ ;
        }

        return unique;
    }
};