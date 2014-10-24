/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        if (root->left==NULL && root->right==NULL) return 1;
        int l, r;
        l = r = 0x7fffffff;
        if (root->left)  l = minDepth(root->left);
        if (root->right) r = minDepth(root->right);
        return l<r ? (l+1):(r+1);
    }
};
