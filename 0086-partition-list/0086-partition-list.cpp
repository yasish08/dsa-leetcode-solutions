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
    ListNode* partition(ListNode* head, int x) {
       ListNode*dummy1=new ListNode(0);
       ListNode*prev1=dummy1;
       ListNode*dummy2=new ListNode(0);
       ListNode*prev2=dummy2;
       ListNode*temp=head;
       while(temp!=NULL){
        if(temp->val<x){
            prev1->next=temp;
            prev1=prev1->next;
        }
        else{
           prev2->next=temp; 
           prev2=prev2->next;
        }
        temp=temp->next;
       }
       prev1->next=dummy2->next;
       prev2->next=NULL;
       return dummy1->next;
    }
};