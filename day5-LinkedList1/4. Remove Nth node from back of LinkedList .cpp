class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *left=head,*right=head,*prev=head;
        while(--n) right=right->next; // *****imp edge case*****
        while(right->next!=NULL){
            prev=left;
            left=left->next;
            right=right->next;
        }
        if(prev==left){ // *****imp edge case*****
            head=head->next;
            delete(left);
            return head; 
        }
        prev->next = prev->next->next;
        delete(left);
        return head;
    }
};
// time: O(n) -> one pass , Space :O(1)
