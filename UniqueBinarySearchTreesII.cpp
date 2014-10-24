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
	vector<TreeNode *> generate(int start, int end) {
		vector<TreeNode *> res;
		if (start == end) {
			TreeNode *p = new TreeNode(start);
			res.push_back(p);
			return res;
		}
		int i, j, k;
		for (i = start; i <= end; i++) {
			vector<TreeNode *> l, r;
			if (i > start) l = generate(start, i-1);
			if (i < end) r = generate(i+1, end);
			if (start < i && i < end) {
				for (j = 0; j < l.size(); j++) {
					for (k = 0; k < r.size(); k++) {
						TreeNode *p = new TreeNode(i);
						p->left = l[j];
						p->right = r[k];
						res.push_back(p);
					}
				}
			} else if (i == start) {
				for (k = 0; k < r.size(); k++) {
					TreeNode *p = new TreeNode(i);
					p->right = r[k];
					res.push_back(p);
				}
			} else {
				for (j = 0; j < l.size(); j++) {
					TreeNode *p = new TreeNode(i);
					p->left = l[j];
					res.push_back(p);
				}
			}
		}
		return res;
	}
    vector<TreeNode *> generateTrees(int n) {
        if (n < 1) {
			vector<TreeNode *> ans;
			ans.push_back(NULL);
			return ans;
		}
		return generate(1, n);
    }
};
