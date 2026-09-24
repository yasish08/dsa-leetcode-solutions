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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* dummy=new ListNode(0);
        int carry=0;
        ListNode*temp=dummy;
        while(l1!=NULL||l2!=NULL||carry!=0){
           int x=0;
           int y=0;
           if(l1!=NULL){
            x=l1->val;
           }
           if(l2!=NULL){
            y=l2->val;
           }
           int sum=x+y+carry;
           int digit=sum%10;
           carry=sum/10;
           ListNode*newnode=new ListNode(digit);
           temp->next=newnode;
           temp=temp->next;
           if(l1!=NULL){
            l1=l1->next;
           }
           if(l2!=NULL){
            l2=l2->next;
           }
        }
        if(carry){
            temp->next=new ListNode(carry);
        }
        return dummy->next;
    }
};