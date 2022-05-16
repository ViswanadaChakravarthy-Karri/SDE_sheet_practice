bool ancestors(TreeNode* root,int node,vector<int> &res)
{
    if(root==NULL)
        return false;
    if(root->val == node){
        res.push_back(node);
        return true;
    }
    if( ancestors(root->left,node,res) || ancestors(root->right,node,res) ){
        res.push_back(root->val);
        return true;
    }
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    ancestors(A,B,res);
    reverse(res.begin(),res.end());
    return res;
}
