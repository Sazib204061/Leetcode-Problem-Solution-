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
    void f(TreeNode* node, long long level, vector<long long>&ans)
    {
        if(node==NULL)return;
        ans[level]+=node->val;
        f(node->left, level+1, ans);
        f(node->right, level+1, ans);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>ans(100005,0);
        f(root, 1, ans);
        
        vector<long long>result_array;
        for(int i = 0; i<ans.size(); i++)
        {
            if(ans[i]!=0)
            {
                result_array.push_back(ans[i]);
            }
        }
        if(k>result_array.size())return -1;
        sort(result_array.begin(), result_array.end(), greater<long long>());

        return result_array[k-1];
    }
};
