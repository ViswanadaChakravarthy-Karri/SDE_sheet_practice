class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *left=head,*right=head,*prev=head;
        while(--n)                    // *****imp edge case*****
          right=right->next; 
        while(right->next!=NULL){
            prev=left;
            left=left->next;
            right=right->next;
        }
        if(prev==left)                // *****imp edge case*****
          return head->next; 
        
        prev->next = prev->next->next;
        return head;
    }
};
// time: O(n) -> one pass , Space :O(1)
