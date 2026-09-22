/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode*fast=head->next;
        ListNode*slow=head;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* second= slow->next;
        slow->next=NULL;
        ListNode*curr=second;
        ListNode*next;
        ListNode*prev=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        second=prev;
        ListNode* temp1=head;
        ListNode* temp2=second;
        while(temp1!=NULL&&temp2!=NULL){
            ListNode* next1=temp1->next;
            ListNode* next2=temp2->next;
            temp1->next=temp2;
            temp2->next=next1;
            temp1=next1;
            temp2=next2;
        }
    }
};