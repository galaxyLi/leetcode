/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *f(ListNode *p, ListNode *q) {
        ListNode *head = new ListNode(0);
        ListNode *list = head;
        while ((p!=NULL) && (q!=NULL)) {
            if (p->val < q->val) {
                list->next = p;
                list = list->next;
                p = p->next;
            } else {
                list->next = q;
                list = list->next;
                q = q->next;
            }
        }
        if (p != NULL) list->next = p;
        else if (q != NULL) list->next = q;
        return head->next;
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        vector<ListNode *> tmplists;
        vector<ListNode *>::iterator i, j;
        bool flag = true;
        while (true) {
            if (flag) {
                for (i = lists.begin(); i != lists.end(); i += 2) {
                    j = i+1;
                    if (j != lists.end()) tmplists.push_back(f(*i, *j));
                    else {
                        tmplists.push_back(*i);
                        break;
                    }
                }
                lists.clear();
                flag = false;
                if (tmplists.size() == 1) break;
            } else {
                for (i = tmplists.begin(); i != tmplists.end(); i += 2) {
                    j = i+1;
                    if (j != tmplists.end()) lists.push_back(f(*i, *j));
                    else {
                        lists.push_back(*i);
                        break;
                    }
                }
                tmplists.clear();
                flag = true;
                if (lists.size() == 1) break;
            }
        }
        if (flag) return lists.front();
        else return tmplists.front();
    }
};
