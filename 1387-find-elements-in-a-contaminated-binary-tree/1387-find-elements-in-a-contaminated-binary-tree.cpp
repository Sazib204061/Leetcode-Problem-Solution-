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
class FindElements {
public:
    map<int, int>present;
    void preorder(TreeNode* root)
    {
        if(root->left!=NULL)
        {
            root->left->val = (root->val)*2+1;
            present[root->left->val] = 1;
            preorder(root->left);
        }
        if(root->right!=NULL)
        {
            root->right->val = (root->val)*2+2;
            present[root->right->val] = 1;
            preorder(root->right);
        }
    }
    
    FindElements(TreeNode* root) {
        present.clear();
        root->val = 0;
        present[0] = 1;
        if(root->left!=NULL)
        {
            root->left->val = (root->val)*2+1;
            present[root->left->val] = 1;
            preorder(root->left);
        }
        if(root->right!=NULL)
        {
            root->right->val = (root->val)*2+2;
            present[root->right->val] = 1;
            preorder(root->right);
        }
    }
    
    bool find(int target) {
        if(present[target])
        {
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */