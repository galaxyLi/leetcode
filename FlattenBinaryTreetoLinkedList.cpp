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
	void f(TreeNode *p, TreeNode *next) {
        if (p == NULL) return;
        if (p->left==NULL && p->right==NULL) {
            p->right = next;
            return;
        }
        if (p->left==NULL) {
            f(p->right, next);
            return;
        }
        if (p->right==NULL) {
            f(p->left, next);
            p->right = p->left;
            p->left = NULL;
            return;
        }
        f(p->right, next);
        f(p->left, p->right);
        p->right = p->left;
        p->left = NULL;
    }
    void flatten(TreeNode *root) {
        f(root, NULL);
    }
};
