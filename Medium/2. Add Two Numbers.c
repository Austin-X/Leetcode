/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *add(struct ListNode *list, int val) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    if (list == NULL) list = node;
    else {
       struct ListNode *p = list;
       while (p->next != NULL) p = p->next;
       p->next = node; 
    }
    return list;
}

struct ListNode *addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *ans = NULL;
    int carry = 0;
    while (l1 != NULL && l2 != NULL) {
        int val = carry == 0 ? l1->val + l2->val : l1->val + l2->val + 1;
        ans = add(ans, val % 10);
        carry = val >= 10 ? 1 : 0;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL) {
        if (carry == 1 && l1->val == 9) ans = add(ans, 0);
        else if (carry == 1) { ans = add(ans, l1->val + 1); carry = 0; }
        else ans = add(ans, l1->val);
        l1 = l1->next;
    }
    while (l2 != NULL) {
        if (carry == 1 && l2->val == 9) ans = add(ans, 0);
        else if (carry == 1) { ans = add(ans, l2->val + 1); carry = 0; }
        else ans = add(ans, l2->val);
        l2 = l2->next;
    }
    if (carry == 1) ans = add(ans, 1);
    return ans;
}
