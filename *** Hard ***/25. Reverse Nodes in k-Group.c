/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int cnt = k, length = 0;
    struct ListNode *temp = head, *p = head, *prev = NULL;
    while (length < k && temp != NULL) { length ++; temp = temp->next; }
    if (length < k) return head;

    while (p != NULL && cnt-- > 0) {
        struct ListNode *q = p->next;
        p->next = prev; prev = p; p = q;
    }
    head->next = reverseKGroup(p, k);
    return prev;
}
