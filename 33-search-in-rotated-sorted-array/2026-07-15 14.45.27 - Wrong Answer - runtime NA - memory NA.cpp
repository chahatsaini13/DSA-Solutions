class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int low = 0;
        int high = nums.size() - 1;
        int res = 0;
        while(low <= high){
            int guess = (low + high) / 2;
            if(nums[guess] >= nums[0]){
                low = guess + 1;
            }else{
                res = guess;
                high = guess - 1;
            }
        }
        
        if(nums[res] == tar){
            return res;
        }else if(nums[res] < tar && nums[0] > tar){
            int l = res + 1;
            int h = nums.size() - 1;
            while(l <= h){
                int m = (l + h)/2;
                if(m < tar){
                    l = m + 1;
                }else if(m > tar){
                    h = m - 1;
                }else{
                    return m;
                }
            }
        }else{
            int l = 0;
            int h = res - 1;
            while(l <= h){
                int m = (l + h)/2;
                if(m < tar){
                    l = m + 1;
                }else if(m > tar){
                    h = m - 1;
                }else{
                    return m;
                }
            }
        }

        return -1;
    }
};