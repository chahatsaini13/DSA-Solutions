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
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

    void checkPrev(TreeNode* root){
        if(root == nullptr){
            return;
        }

        checkPrev(root->left);

        if(prev != nullptr && prev->val > root->val){
            if(first == nullptr){
                first = prev;
            }
            second = root;
        }
        prev = root;
        
        checkPrev(root->right);
    }

    void recoverTree(TreeNode* root) {
        checkPrev(root);
        swap(first->val, second->val);
    }
};