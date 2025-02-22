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
    string s;
    int ind = 0, desh = 0;

    void f(TreeNode* parent, int lvl_of_its_child)
    {
        while(ind<s.size() && desh == lvl_of_its_child)
        {
            int num = 0;
            while(ind<s.size() && isdigit(s[ind]))  //make node value
            {
                num = num * 10 + s[ind]-'0';
                ind++;
            }

            TreeNode* node = new TreeNode(num);
            if(parent->left==NULL)
            {
                parent->left = node;
            }
            else parent->right = node;

            desh = 0;

            while(ind<s.size() && s[ind]=='-')   //calculate new desh coutnt
            {
                desh++;
                ind++;
            }

            f(node, lvl_of_its_child+1);
        }
    }

    TreeNode* recoverFromPreorder(string traversal) {
        s = traversal;
        TreeNode* root = new TreeNode(-1);
        f(root, 0);  //f(node and node ar child ar level)

        return root->left;
    }
};