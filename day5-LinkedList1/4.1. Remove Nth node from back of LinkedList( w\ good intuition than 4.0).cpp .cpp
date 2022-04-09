class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *start=new ListNode(); // **Intuition**
        start->next=head;
        ListNode *slow=start,*fast=start;
        for(int i=1; i<=n ; i++) 
            fast=fast->next;
        while(fast->next != NULL) {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next = slow->next->next; // we are able to do this w/o any doubt bcz #nodes>=2 bcz of dummy node
        return start->next; //bcz start is not the head, its a dummy before head
    }
};
// time: O(n) -> one pass , Space :O(1)
