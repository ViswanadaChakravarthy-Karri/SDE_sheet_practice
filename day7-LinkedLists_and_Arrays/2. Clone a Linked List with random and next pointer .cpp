// Brute Force is of O(n) time & O(n) for map
class Solution {
public:
    Node* copyRandomList(Node* head) {
       if(head==NULL)
           return head;
        Node *h_tmp=head;
        Node *clone=new Node(0);
        Node *c_tmp=clone;
        
        // step1: make deep copies of nodes
        while(h_tmp!=NULL){
            Node *cnode=new Node(h_tmp->val);
            cnode->next=h_tmp->next;
            h_tmp->next=cnode;
            h_tmp=cnode->next;
        }
        // step2: initialise Random ptrs
        h_tmp=head;
        while(h_tmp!=NULL){
            if(h_tmp->random==NULL)
                h_tmp->next->random=NULL;
            else
                h_tmp->next->random = h_tmp->random->next;
            h_tmp=h_tmp->next->next;
        }
        // step3: rearrange nxt ptrs
        clone->next=head->next;
        h_tmp=head;
        while(h_tmp!=NULL){
            c_tmp = c_tmp->next = h_tmp->next;
            h_tmp = h_tmp->next = c_tmp->next;
        }
        return clone->next;
    }
};
// Time: O(n), Space: O(1)
