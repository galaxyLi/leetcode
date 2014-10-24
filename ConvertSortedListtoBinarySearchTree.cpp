/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
        TreeNode *f(ListNode *p, int len) {
            if (len <= 0) return NULL;
            if (len == 1) {
                TreeNode *root = new TreeNode(p->val);
                return root;
            }
            int mid = (len%2==0) ? (len/2):(len/2+1);
            ListNode *md = p;
            for (int i = 1; i < mid; i++) md = md->next;
            TreeNode *root = new TreeNode(md->val);
            root->left = f(p, mid-1);
            root->right = f(md->next, len-mid);
            return root;
        }
        TreeNode *sortedListToBST(ListNode *head) {
            ListNode *p = head;
            int len = 0;
            while (p) {
                len++;
                p = p->next;
            }
            return f(head, len);
        }
};
