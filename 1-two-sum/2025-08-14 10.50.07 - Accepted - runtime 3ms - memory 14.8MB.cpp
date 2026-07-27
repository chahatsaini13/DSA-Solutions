class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        unordered_map<int,int> m;
        vector<int> ans;

        for(int i=0; i<arr.size(); i++){
            int f = arr[i];
            int s = tar - f;
            if(m.find(s) != m.end()){
                ans.push_back(i);
                ans.push_back(m[s]);
                break;
            }
            m[f] = i;
        }

        return ans;
    }
};