class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m=0,n=0;
        ListNode *i=headA, *j=headB;
        while(i) m++, i=i->next;
        while(j) n++, j=j->next;
        
        i=headA, j=headB;
        while(m>n) --m, i=i->next;
        while(n>m) --n, j=j->next;
        
        while(i && j){
            if(i==j) 
                return i;
            i=i->next, j=j->next;
        }
        return NULL;
    }
};
// a solution that runs in O(m + n) time and use only O(1) memory
