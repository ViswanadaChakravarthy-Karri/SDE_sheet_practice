// using recursion
class Solution {
public:
    // left , root, right
    void inorder(TreeNode* root,vector<int> &res){
        if(root==NULL)
            return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};
// Time : O(n), Space: O(n) in skewed trees
