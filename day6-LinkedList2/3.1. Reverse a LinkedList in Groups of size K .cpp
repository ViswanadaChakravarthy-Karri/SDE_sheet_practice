ListNode* reverseKGroup(ListNode* head, int k) {
        
        //count len(LL)
        ListNode *temp=head;
        int count=0;
        while(temp!=NULL) temp=temp->next, count += 1;
        
        if( count < 2 ) return head;
        
        ListNode *dum=new ListNode(0,head);
        ListNode *prev=dum;
        ListNode *curr=prev->next;
        ListNode *nex=curr->next;
        
        int i=0; 
        while(count>=k ){
            
            for(int i=k-1 ; i>0 ; i--){
                curr->next=nex->next;
                nex->next=prev->next; // not curr
                prev->next=nex;
                nex=curr->next;
            }
            count -= k;
            prev=curr;
            curr=nex;
            if(curr != NULL) nex=curr->next;
        }
        return dum->next;
    }
