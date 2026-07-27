class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDel = arr[0];
        int oneDel = INT_MIN;
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int prevNoDel = noDel;
            int prevOneDel = oneDel;

            noDel = max(prevNoDel + arr[i], arr[i]);

            if (prevOneDel == INT_MIN)
                oneDel = prevNoDel;
            else
                oneDel = max(prevOneDel + arr[i], prevNoDel);

            ans = max(ans, max(noDel, oneDel));
        }

        return ans;
    }
};