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
    bool walk(ListNode *p1, ListNode* p2) {
        if (p1 == nullptr || p2 == nullptr) {
            return false;
        }
        if (p1 == p2) {
            return true;
        }
        if (p2->next == nullptr) {
            return false;
        }
        return walk(p1->next, p2->next->next);
    }
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        return walk(head, head->next);
    }
};
