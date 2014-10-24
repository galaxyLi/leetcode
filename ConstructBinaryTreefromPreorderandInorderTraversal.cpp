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
        TreeNode *f(vector<int> &in, int is, int ie, vector<int> &pre, int ps, int pe) {
            if (is > ie || ps > pe) return NULL;
            int mid, dis;
            TreeNode *root = new TreeNode(pre[ps]);
            for (int i = is; i <= ie; i++) {
                if (in[i] == root->val) {
                    mid = i;
                    break;
                }
            }
            dis = mid-is;
            root->left = f(in, is, mid-1, pre, ps+1, ps+dis);
            root->right = f(in, mid+1, ie, pre, ps+dis+1, pe);
            return root;
        }
        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
            if (inorder.empty() || preorder.empty()) return NULL;
            if (inorder.size() != preorder.size()) return NULL;
            return f(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1);
        }
};
