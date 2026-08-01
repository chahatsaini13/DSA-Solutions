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
    bool res = false;

    void pathSum(TreeNode* root, int target, int sum) {
        if(root == nullptr){
            return;
        }

        sum += root->val;

        if(root->left == nullptr && root->right == nullptr){
            if(sum == target){
                res = true;
            }
        }

        pathSum(root->left, target, sum);
        pathSum(root->right, target, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        pathSum(root, targetSum, 0);
        return res;
    }
};