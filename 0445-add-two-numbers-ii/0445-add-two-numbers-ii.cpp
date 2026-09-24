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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*curr=l1;
        ListNode*next;
        ListNode*prev=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode*curri=l2;
        ListNode*nexti;
        ListNode*previ=NULL;
        while(curri!=NULL){
            nexti=curri->next;
            curri->next=previ;
            previ=curri;
            curri=nexti;
        }
        ListNode*dummy=new ListNode(0);
        ListNode*temp=dummy;
        int carry=0;
        while(previ!=NULL||prev!=NULL||carry!=0){
            int x=0;
            int y=0;
            if(previ!=NULL){
                y=previ->val;
            }
            if(prev!=NULL){
                x=prev->val;
            }
            int sum=x+y+carry;
            int digit=sum%10;
            carry=sum/10;
            temp->next=new ListNode(digit);
            temp=temp->next;
            if(previ!=NULL){
                previ=previ->next;
            }
            if(prev!=NULL){
                prev=prev->next;
            }
        }
        ListNode* currAns = dummy->next;
        ListNode* prevAns = NULL;

        while(currAns != NULL) {
            ListNode* nextAns = currAns->next;

            currAns->next = prevAns;

            prevAns = currAns;
            currAns = nextAns;
        }

        return prevAns;
    }
};