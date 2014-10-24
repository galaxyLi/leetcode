/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// ·ÇµÝ¹é 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode *> sta;
        TreeNode *p = root;
        while (!sta.empty() || p) {
            if (p) {
                sta.push(p);
                p = p->left;
            } else {
                p = sta.top();
                ans.push_back(p->val);
                p = p->right;
                sta.pop();
            }
        }
        return ans;
    }
};


// µÝ¹é 
class Solution {
public:
    void f(TreeNode *p, vector<int> &vec) {
        if (p == NULL) return;
        if (p->left != NULL) f(p->left, vec);
        vec.push_back(p->val);
        if (p->right != NULL) f(p->right, vec);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        f(root, ans);
        return ans;
    }
};
