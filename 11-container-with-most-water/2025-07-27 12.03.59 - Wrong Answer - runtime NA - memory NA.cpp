class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxArea = 0;
        while(left < right){
            int width = right - left;
            int ht = min(height[right], height[left]);
            int area = width * ht;
            maxArea = max(maxArea, area);
            if(left < right){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};