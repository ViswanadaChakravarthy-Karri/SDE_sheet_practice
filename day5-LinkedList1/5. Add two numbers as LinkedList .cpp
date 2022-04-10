class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy,*dummy_last;
        dummy_last = dummy = new ListNode(0,NULL); // remember dummy->nxt should be returned.
        
        int carry=0;
        while(l1 || l2 || carry>0){
            ListNode *tmp;
            int sum = 0;
            sum += carry;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            tmp = new ListNode(sum % 10,NULL);
            carry = sum / 10;
            dummy_last = dummy_last->next = tmp;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return dummy->next;    
    }
};
