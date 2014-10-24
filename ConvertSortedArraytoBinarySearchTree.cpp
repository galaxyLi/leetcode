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
        TreeNode *f(vector<int> &vec, int s, int e) {
            if (s > e) return NULL;
            int mid = (s+e)/2;
            TreeNode *root = new TreeNode(vec[mid]);
            root->left = f(vec, s, mid-1);
            root->right = f(vec, mid+1, e);
            return root;
        }
        TreeNode *sortedArrayToBST(vector<int> &num) {
            return f(num, 0, num.size()-1);
        }
};
