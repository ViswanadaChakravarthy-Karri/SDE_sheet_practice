class Solution {
  public:
    void findBottomView(Node *root,int ind,map<int,int> &mp){
        if(root==NULL) 
            return;
        
        mp[ind]=root->data;
        
        findBottomView(root->left,ind-1,mp);
        findBottomView(root->right,ind+1,mp);
    }
    vector<int> bottomView(Node *root) {
        map<int,int> mp;
        findBottomView(root,0,mp);
        vector<int> res;
        for(auto i:mp)
            res.push_back(i.second);
        return res;
    }
};
// why not working......???☹️
// bcz you also need to keep count of height/level , we need to make sure that high level will be in map DS
