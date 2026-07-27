class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        for(int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }

        if(pivot != -1){
            for(int i = n-1; i > pivot; i--){
                if(nums[i] > nums[pivot]){
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }
        }
        
        int start = pivot + 1;
        int end = n - 1;
        while (start <= end)
        {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }

        for(int i = 0; i < n; i++){
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};