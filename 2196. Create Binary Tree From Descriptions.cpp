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
    map<int,pair<int,int>>mp;


    void build(int n, TreeNode* node)
    {
        if(mp[n].first==0 && mp[n].second==0)
        {
            node->left = NULL;
            node->right=NULL;
            return;
        }
        if(mp[n].first!=0)
        {
            TreeNode* l = new TreeNode();
            l->val = mp[n].first;
            node->left = l;
            build(mp[n].first, l);
        }
        if(mp[n].second!=0)
        {
            TreeNode* r = new TreeNode();
            r->val = mp[n].second;
            node->right = r;
            build(mp[n].second, r);
        }
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        mp.clear();
        map<int,int>nd;
        int n = descriptions.size();
        for(int i = 0; i<n; i++)
        {
            if(nd[descriptions[i][0]]==0)
            {
                nd[descriptions[i][0]] = 1;
            }
            nd[descriptions[i][1]] = -1;
            if(descriptions[i][2]==1)
            {
                mp[descriptions[i][0]].first = descriptions[i][1];
            }
            else
            {
                mp[descriptions[i][0]].second = descriptions[i][1];
            }
        }
        int root_node;
        for(auto it : nd)
        {
            if(it.second!=-1)
            {
                root_node = it.first;
                break;
            }
        }


        /*for(auto it : mp)
        {
            cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        }*/

        TreeNode*ans = new TreeNode();
        ans->val = root_node;
        build(root_node, ans);
        return ans;
    }
};
