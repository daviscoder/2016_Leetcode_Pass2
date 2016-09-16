/**
 * 两种解法：recursion和iteration.
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Recursion
class Solution {
public:
    ListNode* helper (ListNode* head, ListNode* tail) {
        if (head == NULL)
            return tail;
        ListNode * nextHead = head->next;
        head->next = tail;
        return helper (nextHead, head);
    }
    ListNode* reverseList(ListNode* head) {
        return helper (head, NULL);
    }
};
 
// Iteration.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *p = head, *q = head->next;
        p->next = NULL;
        while (q) {
            ListNode *tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        return p;
    }
};
