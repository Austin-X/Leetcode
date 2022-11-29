/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *addNode(struct ListNode *tail, int val) {
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val; newNode->next = NULL;
    if (tail == NULL) tail = newNode;
    else { tail->next = newNode; tail = newNode; }
    return tail;
}

void mergeSort(struct ListNode **lists, int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    mergeSort(lists, l, mid);
    mergeSort(lists, mid + 1, r);
    struct ListNode *li = lists[l], *ri = lists[mid + 1];
    struct ListNode *head = NULL, *tail = head;
    while (li != NULL && ri != NULL) {
        if (li->val <= ri->val) { tail = addNode(tail, li->val); head = head == NULL ? tail : head; li = li->next; }
        else { tail = addNode(tail, ri->val); head = head == NULL ? tail : head; ri = ri->next; }
    }
    while (li != NULL) { tail = addNode(tail, li->val); head = head == NULL ? tail : head; li = li->next; }
    while (ri != NULL) { tail = addNode(tail, ri->val); head = head == NULL ? tail : head; ri = ri->next; }
    lists[l] = head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;

    mergeSort(lists, 0,  listsSize - 1);
    return lists[0];
}
