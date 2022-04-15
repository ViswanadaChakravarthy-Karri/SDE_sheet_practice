ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k==1) return head;
        
        ListNode *dummy=new ListNode(0,head);
        ListNode *pre=dummy, *cur=dummy, *nex=dummy;
        int count=0;
        while(cur->next!=NULL) count++, cur=cur->next;
        
        while(count>=k){
            cur=pre->next;
            nex=cur->next;
            for(int i=1 ; i<k ; i++){
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre = cur;
            count -= k;
        }
        return dummy->next;
}
// Time Complex: O( (n/k)*k ) = O(n) & Space: O(1)
