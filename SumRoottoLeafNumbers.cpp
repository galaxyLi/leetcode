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
    void f(TreeNode *p, vector<string> &vec, string num) {
        if (p->left==NULL && p->right==NULL) {
            num.push_back(p->val+'0');
            vec.push_back(num);
            return;
        }
        num.push_back(p->val+'0');
        if (p->left) f(p->left, vec, num);
        if (p->right) f(p->right, vec, num);
    }
    int sumNumbers(TreeNode *root) {
        if (root == NULL) return 0;
        vector<string> vec;
        string num;
        f(root, vec, num);
        int ans = 0;
        for (int i = 0; i < vec.size(); i++) ans += stoi(vec[i]);
        return ans;
    }
};
