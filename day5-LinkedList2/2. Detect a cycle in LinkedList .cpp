class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *a=head,*b=head;
        while(a && b && a->next && b->next){
            a=a->next;
            b=b->next->next;
            if(a==b) return true;
        }
        return false;
    }
};
// space: O(1), time:O(n)
