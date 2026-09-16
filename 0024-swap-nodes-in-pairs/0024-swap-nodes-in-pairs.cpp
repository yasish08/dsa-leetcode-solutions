class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* first = head;
        while(first != NULL && first->next != NULL) {
            ListNode* second = first->next;
            ListNode* third = second->next;
            second->next = first;
            first->next = third;
            prev->next = second;
            prev = first;
            first = third;
        }
     return dummy.next;
    }
};