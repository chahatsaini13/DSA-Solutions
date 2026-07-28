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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;

        if(root == nullptr){
            return res;
        }

        q.push(root);

        bool leftToRight = true;

        while(!q.empty()){

            int lvlsize = q.size();
            vector<int> temp;

            while(lvlsize--){
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);

                if(t->left != nullptr){
                    q.push(t->left);
                }

                if(t->right != nullptr){
                    q.push(t->right);
                }
            }

            if(!leftToRight){
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);
            leftToRight = !leftToRight;
        }

        return res;
    }
};