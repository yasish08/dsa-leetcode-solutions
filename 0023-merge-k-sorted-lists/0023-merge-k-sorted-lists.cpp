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
    ListNode* mergetwolsits(ListNode*head1,ListNode*head2){
      ListNode*temp1=head1;
      ListNode*temp2=head2;
      ListNode*dummy=new ListNode(0);
      ListNode*prev=dummy;
      while(temp1!=NULL&&temp2!=NULL){
        if(temp1->val<=temp2->val){
            prev->next=temp1;
            prev=prev->next;
            temp1=temp1->next;
        }
        else{
            prev->next=temp2;
            prev=prev->next;
            temp2=temp2->next;
        }
      }  
      while(temp1!=NULL){
         prev->next=temp1;
         prev=prev->next;
         temp1=temp1->next;
      }
      while(temp2!=NULL){
         prev->next=temp2;
         prev=prev->next;
         temp2=temp2->next;
      }
      return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty())
    return NULL;
      ListNode* result=lists[0];
      for(int i=1;i<lists.size();i++){
        result=mergetwolsits(result,lists[i]);
      }
      return result;
    }
};