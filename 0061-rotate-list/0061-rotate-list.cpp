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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode*temp=head;
        if(head==NULL||head->next==NULL){
            return head;
        }
        int n=0;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        temp=head;
        if(head!=NULL){
           k=k%n;
        }
       
        for(int i=1;i<n-k;i++){
            temp=temp->next;
        }
        ListNode*newhead=temp->next;
        temp->next=NULL;
        return newhead;
    }
};