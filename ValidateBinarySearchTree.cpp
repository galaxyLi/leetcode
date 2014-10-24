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
    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;
        stack<TreeNode *> stk;
        int pre = 0x80000000;
        TreeNode *p = root;
        while (!stk.empty() || p) {
            while (p) {
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            if (p->val <= pre) return false;
            pre = p->val;
            p = p->right;
        }
        return true;
    }
};
