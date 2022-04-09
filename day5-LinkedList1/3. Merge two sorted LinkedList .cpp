class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL) return NULL;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        vector<ListNode*> ans;
        while(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val){
                ans.push_back(list1);
                list1=list1->next;
            }
            else{
                ans.push_back(list2);
                list2=list2->next;
            }
        }
        if(list1==NULL) ans.push_back(list2);
        if(list2==NULL) ans.push_back(list1);
        
        for(int i=0 ; i<ans.size()-1 ; i++) ans[i]->next=ans[i+1];
        
        return ans[0];
    }
};

// Time : O(n+n), Space: O(n)
// Same as merge() method in MergeSort
