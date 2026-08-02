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
    int sumLeaf(TreeNode* root, int num){
        if(root == nullptr){
            return 0;
        }

        num = num * 10 + root->val;

        if(root->left == nullptr && root->right == nullptr){
            return num;
        }

        return sumLeaf(root->left, num) + sumLeaf(root->right, num);
    }


    int sumNumbers(TreeNode* root) {
        return sumLeaf(root, 0);
    }
};