class Solution {
public:
    int max_arr(vector<int>& arr){
        int max = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    long long hours(vector<int>& arr, int speed){
        long long h = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            h = h + (arr[i]/speed);
            if(arr[i] % speed != 0){
                h++;
            } 
        }
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = max_arr(piles);
        int res = 1;
        while(low <= high){
            int guess = (low + high) / 2;
            long long hour = hours(piles, guess);
            if(hour > h){
                low = guess + 1;
            }else{
                res = guess;
                high = guess - 1;
            }
        }

        return res;
    }
};