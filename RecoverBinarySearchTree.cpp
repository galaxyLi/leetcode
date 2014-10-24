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
    void recoverTree(TreeNode *root) {
        if (root == NULL) return;
        TreeNode *p;
		stack<TreeNode *> stk;
		vector<TreeNode *> vec;
		vector<int> value;
		p = root;
		while (!stk.empty() || p!=NULL) {
			while (p != NULL) {
				stk.push(p);
				p = p->left;
			}
			p = stk.top();
			vec.push_back(p);
			value.push_back(p->val);
			stk.pop();
			p = p->right;
		}
		sort(value.begin(), value.end());
		int i, j, index[2];
		for (i = 0, j = 0; i < vec.size(); i++) {
			if (vec[i]->val != value[i]) index[j++] = i;
		}
		swap(vec[index[0]]->val, vec[index[1]]->val);
    }
};
