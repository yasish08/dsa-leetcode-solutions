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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*curr=head;
        ListNode*beforeleft=NULL;
        for(int i=1;i<left;i++){
           beforeleft=curr;
           curr=curr->next;
        }
        ListNode* leftnode=curr;
        ListNode*prev=NULL;
        ListNode*next;
        for(int i=left;i<=right;i++){
             next=curr->next;
             curr->next=prev;
             prev=curr;
             curr=next;
        }
        if(beforeleft!=NULL){
            beforeleft->next=prev;
        }
        else{
            head=prev;
        }
        leftnode->next=curr;
        return head;
    }
};