/**
 * logk * O(n), k.
 */
class Solution {
public:
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> heap;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL)
                heap.push (lists[i]);
        }
        ListNode * fakeHead = new ListNode (-1), * p = fakeHead;
        while (heap.empty() == false) {
            p->next = heap.top();
            p = p->next;
            heap.pop();
            if (p->next)
                heap.push(p->next);
        }
        return fakeHead->next;
    }
};
