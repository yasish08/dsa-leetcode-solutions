class MyLinkedList {
public:
    class listnode{
    public:
        int val;
        listnode* next;
        listnode(int x){
             val=x;
             next=NULL;
        }
    };
    listnode*head=NULL;
    int size = 0;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if(index < 0 || index >= size)
        return -1;
        if(head==NULL){
            return -1;
        }
        listnode*temp=head;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        listnode*newnode=new listnode(val);
        newnode->next=head;
        head=newnode;
        size++;
        
    }
    
    void addAtTail(int val) {
        listnode*newnode=new listnode(val);
        if(head==NULL){
           head=newnode;
           size++;
           return; 
           
        }
        listnode*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        listnode*newnode=new listnode(val);
        if(index==0){
            newnode->next=head;
            head=newnode;
            size++;
            return;
        }
        listnode*temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        listnode* temp=head;
        if(index < 0 || index >= size)
        return;
        if(index==0){
            head=head->next;
            size--;
            return;
        }
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        size--;
    }
};
