class Solution {
public:
    int threeSumClosest(vector<int>& nums, int sum) {
        int n = nums.size();
        int ans;
        sort(nums.begin(), nums.end());
        int diff;
        int max_diff = INT_MAX;
        for(int i=0; i<n-2; i++){
            
            int left = i+1, right = n-1;

            while(left<right){
                int s = nums[left] + nums[right] + nums [i];
                diff = abs(sum - s);

                if(diff < max_diff){
                    max_diff = diff;
                    ans = s;
                }

                if(s == sum){
                    return ans;
                }
                else if(s < sum){
                    left++ ;
                }
                else{
                    right-- ;
                }
            }
        }
        return ans; 
    }
};