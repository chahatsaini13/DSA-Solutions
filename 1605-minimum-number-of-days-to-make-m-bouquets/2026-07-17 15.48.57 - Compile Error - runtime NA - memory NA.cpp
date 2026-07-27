class Solution {
public:
    int minval(vector<int>& arr){
        int min = INT_MAX;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] < min){
                min  = arr[i];
            }
        }
        return min;
    }

    int maxval(vector<int>& arr){
        int max = INT_MIN;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > max){
                max  = arr[i];
            }
        }
        return max;
    }

    int b(vector<int>& arr, int g, int flower){
        int count = 0;
        int bouquet = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] <= g){
                count++;
                if(count == flower){
                    bouquet++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }
        return bouquet;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if(n < (long long(m*k))){
            return -1;
        }

        int low = minval(bloomDay);
        int high = maxval(bloomDay);
        int res = 0;
        while(low <= high){
            int guess = (low + high) / 2;
            int bouq = b(bloomDay, guess, k);
            if(bouq < m){
                low = guess + 1;
            }else{
                res = guess;
                high = guess-1;
            }
        }
        return res;
    }
};