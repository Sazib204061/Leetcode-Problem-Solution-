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


TreeNode* sortedListToBSTRecur(vector<int>& vec, int start, int end){
    if(start > end) return NULL;
    int mid = start + (end-start)/2;
    if((end - start)%2 != 0) mid = mid+1;
    TreeNode* root = new TreeNode(vec[mid]);
    root->left = sortedListToBSTRecur(vec, start, mid-1);
    root->right = sortedListToBSTRecur(vec, mid+1, end);
    return root;
}

void preOrder(vector<int>& vec,TreeNode* root){
    if(root == NULL) return;
    //cout<<root->data<<" ";
    vec.push_back(root->val);
    preOrder(vec,root->left);
    preOrder(vec,root->right);
}
 

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        preOrder(vec, root);
        sort(vec.begin(), vec.end());
        return sortedListToBSTRecur(vec, 0, vec.size()-1);
    }
};
