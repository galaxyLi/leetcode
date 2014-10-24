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
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        TreeNode *p;
        vector<vector<int>> ans;
        vector<int> tmp;
        if (root == NULL) return ans;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            p = q.front();
            if (p) {
                tmp.push_back(p->val);
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
                q.pop();
            } else {
                if (tmp.size() == 0) break;
                q.pop();
                q.push(NULL);
                ans.push_back(tmp);
                tmp.clear();
            }
        }
    }
};
