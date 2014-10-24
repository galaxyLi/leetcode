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
    bool solve(TreeNode *p, int &len) {
        if (p == NULL) return true;
        int ll, lr;
        ll = lr = 0;
        if (!solve(p->left, ll)) return false;
        if (!solve(p->right, lr)) return false;
        len = max(ll, lr)+1;
        if (ll-lr>1 || lr-ll>1) return false;
        return true;
    }
    
    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;
        int ll, lr;
        ll = lr = 0;
        if (!solve(root->left, ll) || !solve(root->right, lr) || lr-ll>1 || ll-lr>1) return false;
        return true;
    }
};
