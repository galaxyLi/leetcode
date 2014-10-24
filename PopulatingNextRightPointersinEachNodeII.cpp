/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeLinkNode *tp = q.front();
            q.pop();
            if (tp == NULL) break;
            if (tp->left) q.push(tp->left);
            if (tp->right) q.push(tp->right);
            TreeLinkNode *next = q.front();
            tp->next = next;
            if (next == NULL) {
                q.pop();
                q.push(NULL);
            }
        }
    }
};
