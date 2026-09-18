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
    ListNode* reverse(ListNode*head,ListNode*temp){
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*next;
        while(curr!=temp){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode*prev=dummy;
        while(head!=NULL){
            ListNode*temp=head;
            int cnt=0;
            while(temp!=NULL &&cnt<k){
                temp=temp->next;
                cnt++;
            }
            if(cnt<k){
                break;
            }
            ListNode* newhead=reverse(head,temp);
            prev->next=newhead;
            head->next=temp;
            prev=head;
            head=temp;
        }
        return dummy->next;
    }
};