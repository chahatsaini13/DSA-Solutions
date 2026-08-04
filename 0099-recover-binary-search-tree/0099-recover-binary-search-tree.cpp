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
    int glt = 0;
    TreeNode* g1first = nullptr;
    TreeNode* g1second = nullptr;
    TreeNode* g2first = nullptr;
    TreeNode* g2second = nullptr;

    void previous(TreeNode* root){
        if(root == nullptr){
            return;
        }

        previous(root->left);
        if(prev == nullptr){
            prev = root;
        }
        else{
            if(prev->val > root->val){
                if(glt == 0){
                    g1first = prev;
                    g1second = root;
                }
                else{
                    g2first = prev;
                    g2second = root;
                }
                glt++;
            }
            prev = root;
        }
        previous(root->right);
    }

    void recoverTree(TreeNode* root) {
        previous(root);

        if(glt == 1){
            swap(g1first->val, g1second->val);
        }
        else{
            swap(g1first->val, g2second->val);
        }
    }
};