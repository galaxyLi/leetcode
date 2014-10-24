/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* ·ÇµÝ¹é */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode *> stk;
        stack<TreeNode *> out;
        if (root == NULL) return ans;
        TreeNode *p = root;
        stk.push(p);
        while (!stk.empty()) {
            p = stk.top();
            out.push(p);
            stk.pop();
            if (p->left) stk.push(p->left);
            if (p->right) stk.push(p->right);
        }
        while (!out.empty()) {
            p = out.top();
            ans.push_back(p->val);
            out.pop();
        }
        return ans;
    }
};

/* µÝ¹é */
class Solution {
public:
    void f(TreeNode *p, vector<int> &vec) {
        if (p == NULL) return;
        if (p->left != NULL) f(p->left, vec);
        if (p->right != NULL) f(p->right, vec);
        vec.push_back(p->val);
    }
    
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        f(root, ans);
        return ans;
    }
};
