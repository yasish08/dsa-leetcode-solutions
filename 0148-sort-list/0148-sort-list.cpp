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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=NULL&&fast->next!=NULL){
           fast=fast->next->next;
           slow=slow->next;
        }
        ListNode* righthead=slow->next;
        slow->next=NULL;
        ListNode* leftsort=sortList(head);
        ListNode* rightsort=sortList(righthead);
        ListNode*temp1=leftsort;
        ListNode*temp2=rightsort;
        ListNode* dummy=new ListNode(0);
        ListNode* prev=dummy;
        while(temp1!=NULL&&temp2!=NULL){
            if(temp1->val<=temp2->val){
                prev->next=temp1;
                prev=temp1;
                temp1=temp1->next;
            }
            else{
                prev->next=temp2;
                prev=temp2;
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL){
            prev->next=temp1;
            prev=temp1;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            prev->next=temp2;
            prev=temp2;
            temp2=temp2->next;
        }
        return dummy->next;
    }
};