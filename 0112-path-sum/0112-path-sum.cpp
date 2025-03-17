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
    bool f(TreeNode* node, int currSum, int targetSum) {

        if(node==NULL)return false;
        if(node->left==NULL && node->right==NULL)
        {
            currSum+=node->val;
            if(targetSum==currSum)return true;
        }
        bool ans = false;
        if(node->left!=NULL)
        {
            ans|=f(node->left, currSum+node->val, targetSum);
        }
        if(node->right!=NULL)
        {
            ans|=f(node->right, currSum+node->val, targetSum);
        }
        return ans;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return f(root, 0, targetSum);
    }
};