class Solution1
{
  public:
      bool ancestors(TreeNode* root,int node,vector<int> &res)
      {
        if(root==NULL)
            return false;
        if(root->val == node){
            res.push_back(root->val);
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
};
// time : O(#nodes) for both solution 
class Solution2
{
  public:
    bool getPath(TreeNode* root,int node,vector<int> &res)
    {
        if(root==NULL)
            return false;
        res.push_back(root->val);
        if(root->val == node)
            return true;
        if( getPath(root->left,node,res) || getPath(root->right,node,res) )
            return true;
        res.pop_back();
        return false;
    }
    vector<int> Solution::solve(TreeNode* A, int B) {
        vector<int> res;
        getPath(A,B,res);
        return res;
    }
};
