class Solution {
public:
    void printArray(vector<int>& arr, int n){
        for(int i = 0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;

    }

    void sortColors(vector<int>& nums) {
        vector<int> arr = {};
        int n = nums.size();
        int red = 0, white = 0, blue = 0;

        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                red++;
            }else if(nums[i] == 1){
                white++;
            }else{
                blue ++;
            }
        }
        for(int i=0; i < red; i++){
            arr.push_back(0);
        }

        for(int i=0; i < white; i++){
            arr.push_back(1);
        }

        for(int i=0; i < blue; i++){
            arr.push_back(2);
        }

        for (int i = 0; i < n; i++) {
            nums[i] = arr[i];
        }
    }
};