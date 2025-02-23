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
    void idenfity_used_node(vector<int>&postorder, vector<int>&used, int node)
    {
        for(int i = 0; i<used.size(); i++)
        {
            if(postorder[i]==node)
            {
                used[i] = 1;
                break;
            }
        }
    }
    int next_used(vector<int>&postorder, vector<int>&used, int node)
    {
        for(int i = 0; i<used.size(); i++)
        {
            if(postorder[i]==node)
            {
                i++;
                while(i<used.size())
                {
                    if(used[i]==1)
                    {
                        return postorder[i];
                    }
                    i++;
                }
                break;
            }
        }
        return 0;
    }

    void add_new_node(TreeNode* root, int parent, int new_child)
    {
        
        //cout<<root->val<<" "<<parent<<" "<<new_child<<endl;
        if(root->val==parent)
        {
            TreeNode* new_node = new TreeNode(new_child);
            if(root->left==NULL)
            {
                root->left = new_node;
            }
            else
            {
                root->right = new_node;
            }
            return;
        }
        if(root->left!=NULL)
        {
            add_new_node(root->left, parent, new_child);
        }
        if(root->right!=NULL)
        {
            add_new_node(root->right, parent, new_child);
        }
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        map<int,vector<int>>LR;

        vector<int>used(n,0);

        idenfity_used_node(postorder, used, preorder[0]);
        TreeNode* root = new TreeNode(preorder[0]);

        for(int i = 1; i<n; i++)
        {
            int node = preorder[i];
            int next_used_node = next_used(postorder, used, node);
            //cout<<preorder[i]<<" "<<next_used_node<<endl;

            add_new_node(root, next_used_node, node);

            LR[next_used_node].push_back(node);
            idenfity_used_node(postorder, used, node);
        }

        // for(auto it : LR)
        // {
        //     vector<int>ar = it.second;
        //     cout<<it.first<<" -> ";
        //     for(int i = 0; i<ar.size(); i++)
        //     {
        //         cout<<ar[i]<<" ";
        //     }
        //     cout<<endl;
        // }

        

        

        return root;
    }
};