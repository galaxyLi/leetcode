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
        public:
        TreeNode *f(vector<int> &in, int is, int ie, vector<int> &post, int ps, int pe) {
            if (is > ie || ps > pe) return NULL;
            int mid, dis;
            TreeNode *root = new TreeNode(post[pe]);
            for (int i = is; i <= ie; i++) {
                if (in[i] == root->val) {
                    mid = i;
                    break;
                }
            }
            dis = mid-is;
            root->left = f(in, is, mid-1, post, ps, ps+dis-1);
            root->right = f(in, mid+1, ie, post, ps+dis, pe-1);
            return root;
        }
        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
            if (inorder.empty() || postorder.empty()) return NULL;
            if (inorder.size() != postorder.size()) return NULL;
            return f(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
        }

};
