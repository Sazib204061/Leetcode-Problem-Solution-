/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
 #define fast ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
class Solution {
public:
    bool ans = false;
    bool f2(TreeNode* node, ListNode* head)
    {
        if(head==NULL)return true;
        if(node==NULL)return false;
        if(node->val==head->val)
        {
            ans|=f2(node->left, head->next);
            ans|=f2(node->right, head->next);
        }
        return ans;
    }

    bool f(TreeNode* node, ListNode* head)
    {
        if(node==NULL)return false;
        if(node->val==head->val)
        {
            ans|=f2(node, head);
        }
        if(ans==true)return ans;
        else
        {
            ans|=f(node->left, head);
            ans|=f(node->right, head);
        }
        return ans;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        fast;
        ans = false;
        return f(root, head);
    }
};
