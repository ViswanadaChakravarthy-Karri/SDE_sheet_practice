class Solution {
public:
    int length(ListNode* start){
        int count=0;
        while(start!=NULL) 
            start=start->next, count++;
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len=length(head);
        if(len<=1 || k==0)
            return head;
        
        int fdist= len - (k % len);
        ListNode *tmp=head;
        while(tmp->next != NULL) 
            tmp=tmp->next;
        tmp->next=head;
        while(fdist--)
            tmp=tmp->next;
        head=tmp->next;
        tmp->next=NULL;
        return head;
    }
};
