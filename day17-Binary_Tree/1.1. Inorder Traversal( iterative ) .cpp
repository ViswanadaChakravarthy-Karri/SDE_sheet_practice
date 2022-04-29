class Solution {
public:
    // left , root, right
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while(true){
            if(root!=NULL) 
            st.push(root),root=root->left;
            else{
                if(st.empty())
                    break;
                root=st.top();
                st.pop();
                res.push_back(root->val);
                root=root->right;
            }
        }
        
        return res;
    }
};
// Time: O(n), space:O(H)
