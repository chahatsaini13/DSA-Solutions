class Solution {
public:
    long long max_arr(vector<int>& arr){
        long long max = INT_MIN;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }

        return max;
    }

    long long sum(vector<int>& arr){
        long long sum = 0;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
        }

        return sum;

    }

    long long candies(vector<int>& arr, long long candy){
        long long children = 0;
        for(int i = 0; i < arr.size(); i++){
            int n = arr[i] / candy;
            children += n;
        }

        return children;

    }

    long long maximumCandies(vector<int>& arr, long long k) {
        if(sum(arr) < k){
            return 0;
        }

        long long l = 1;
        long long h = max_arr(arr);
        long long res = 0;

        while(l<=h){
            long long guess = (l+h) / 2;
            long long children = candies(arr, guess);
            if(children >= k){
                res = guess;
                l = guess + 1;
            }else{
                h = guess - 1;
            }
        }

        return res;
    }
};