class Solution {
public:
    // ab+
    void postorder(TreeNode* root,vector<int> &res){
        if(root==NULL)
            return;
        postorder(root->left,res);
        postorder(root->right,res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root,res);
        return res;
    }
};
// Time: O(#nodes) , Space: O(H)
