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
    void f(vector<vector<int> > &vec, vector<int> tmp, TreeNode *p, int sum) {
        if (p == NULL) return;
        if (p->left==NULL && p->right==NULL) {
            if (p->val == sum) {
            	tmp.push_back(sum);
            	vec.push_back(tmp);
            }
        } else {
        	tmp.push_back(p->val);
            f(vec, tmp, p->left, sum-p->val);
            f(vec, tmp, p->right, sum-p->val);
        }
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ans;
        vector<int> tmp;
        f(ans, tmp, root, sum);
        return ans;
    }
};
