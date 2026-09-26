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
    ListNode* removeNodes(ListNode* head) {
      ListNode*temp=head;
      stack<int>st;
      while(temp!=NULL){
        while(!st.empty()&&st.top()<temp->val){
            st.pop();
        }
        st.push(temp->val);
        temp=temp->next;
      }
      ListNode*newnode=NULL;
      while(!st.empty()){
        ListNode*node=new ListNode(st.top());
        node->next=newnode;
        newnode=node;
        st.pop();
      }
      return newnode;
    }
};