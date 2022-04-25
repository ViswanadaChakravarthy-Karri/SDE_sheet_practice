class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)  // here not check for head->nxt bcz at while loop anyhow we're checking 
            return head;
        
        ListNode *slow=head,*fast=head;
        
        while(fast->next && fast->next->next){ 
            // for 1st iteration, until now we've checked if head,head->nxt,head->nxt->nxt is NULL
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                fast=head;
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};

// Time Complexity: O(N)
// Reason: We can take overall iterations club it to O(N)

// Space Complexity: O(1)
// Reason: No extra data structure is used.
