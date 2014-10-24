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
    void reverse(vector<int> &vec) {
        int tmp, len = vec.size();
        for (int i = 0; i < len/2; i++) {
            tmp = vec[i];
            vec[i] = vec[len-1-i];
            vec[len-1-i] = tmp;
        }
    }
    
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        TreeNode *p = root;
        vector<vector<int>> ans;
        vector<int> tmp;
        if (root == NULL) return ans;
        q.push(p);
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
        bool flag = false;
        for (vector<vector<int> >::iterator i = ans.begin(); i != ans.end(); i++) {
            if (flag) {
                reverse(*i);
                flag = false;
            } else flag = true;
        }
        return ans;
    }
};
