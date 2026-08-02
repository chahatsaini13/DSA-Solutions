/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;
    
    void path(TreeNode* root, int target, int sum, vector<int> temp) {
        if(root == nullptr){
            return;
        }
        
        sum += root->val;
        temp.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr){
            if(sum == target){
                res.push_back(temp);
                temp.pop_back();
                return;
            }
        }

        path(root->left, target, sum, temp);
        path(root->right, target, sum, temp);
        temp.pop_back();
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        path(root, targetSum, 0, temp);

        return res;
    }
};