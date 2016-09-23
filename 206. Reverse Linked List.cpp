/**
 * O(n), O(1)
 * 空list， 1个元素，2个，三个及以上
 */

// Iterative.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode * p = head, * q = head->next;
        p->next = NULL;
        while (q) {
            ListNode * tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        return p;
    }
};

// recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode * p = head, * q = head->next;
        p->next = NULL;
        if (q) {
            ListNode * newHead = reverseList (q);
            q->next = p;
            return newHead;
        }
        return p;
    }
};
