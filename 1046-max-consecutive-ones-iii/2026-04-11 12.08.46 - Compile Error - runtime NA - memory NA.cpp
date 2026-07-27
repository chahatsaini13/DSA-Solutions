class Solution {
public:
    int find(vector<int> &f){
        int zcount=-1;
        for(int i=0;i<2;i++){
            zcount = max(zcount,f[i]);
        }    
        return zcount;
    }

    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int res = 0;
        vector<int> f(2,0);
        for(int high=0; high < n; high++){
            f[nums[high]]++;
            int zcount = find(f);
            int len = high - low + 1;
            int diff = len - zcount;
            while(diff > k){
                f[nums[low]]--;
                zcount = find(f);
                len = high - low + 1;
                diff = len - zcount;
            }
            len = high - low + 1;
            res = res(len, res);
        }

        return res;

    }
};