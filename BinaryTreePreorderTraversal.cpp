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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode *> stk;
        TreeNode *p = root;
        if (root == NULL) return ans;

        while (!stk.empty() || p != NULL) {
            while (p != NULL) {
                stk.push(p);
                ans.push_back(p->val);
                p = p->left;
            }
            p = stk.top();
            p = p->right;
            stk.pop();
        }
        return ans;
    }
};
