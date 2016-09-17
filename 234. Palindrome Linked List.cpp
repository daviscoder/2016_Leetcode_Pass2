/**
 * 先翻转后半段Linked List，再比较...
 */
class Solution {
public:
    ListNode* reverse (ListNode * head) {
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *fakeHead = new ListNode (-1);
        fakeHead->next = head;
        ListNode * fast = fakeHead, * slow = fakeHead;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* newHead = reverse (slow->next);
        slow->next = NULL;
        while (newHead && head) {
            if (newHead->val != head->val)
                return false;
            head = head->next;
            newHead = newHead->next;
        }
        return true;
    }
};
