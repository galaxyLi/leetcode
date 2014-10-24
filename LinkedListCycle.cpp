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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *p1, *p2;
        p1 = head;
        p2 = head;
        while (p2->next) {
            p1 = p1->next;
            for (int i = 0; i < 2; i++) {
                if (p2->next) p2 = p2->next;
                else return false;
            }
            if (p1 == p2) return true;
        }
        return false;
    }
};
