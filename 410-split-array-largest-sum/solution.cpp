class Solution {
public:
    bool isPossible(vector<int>& arr, int n, int m, int allowed_time){
        int painter = 1, time = 0;

        for(int i = 0; i<n; i++){
            if(time + arr[i] <= allowed_time){
                time += arr[i];
            }else{
                painter++;
                time = arr[i];
            }
        }

        return painter <=m;
    }

    int splitArray(vector<int>& arr, int m) {
       int n = arr.size();
       int sum =0, maxVal = INT_MIN;
       for(int i = 0; i < n; i ++){
            sum += arr[i];
            maxVal = max(maxVal, arr[i]);
       }

       int st = maxVal, end = sum, ans = -1;

       while(st <= end){
        int mid = st + (end-st)/2;

        if(isPossible(arr, n, m, mid) == true){
            ans = mid;
            end = mid - 1;
        }else{
            st = mid + 1;
        }
       }

       return ans;
    }
};