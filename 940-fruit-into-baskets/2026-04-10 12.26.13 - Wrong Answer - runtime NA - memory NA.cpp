class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size() ;
        int l = 0;
        int res = -1;
        unordered_map<int, int> f ;

        for(int h = 0; h<n ; h++){
            f[fruits[h]]++ ;

            while(f.size() > 2){
                f[fruits[l]]-- ;

                if(f[fruits[l]] == 0){
                    f.erase(fruits[l]);
                }

                l++ ;
            }

            if(f.size() == 2){
                int len = h - l + 1;
                res = max(res,len) ;
            }
        }

        return res;
    }
};