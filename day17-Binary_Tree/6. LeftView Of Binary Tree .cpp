void findLeftView(Node* root,int level,vector<int> &res){
    if(root==NULL)    return;
    
    if(level==res.size())    res.push_back(root->data);
    
    findLeftView(root->left,level+1,res); // statement #1
    findLeftView(root->right,level+1,res); // statement #2
}
vector<int> leftView(Node *root)
{
    vector<int> res;
    findLeftView(root,0,res);
    return res;
}
// Time: O(n), Space: O(H) but we can ignore bcz it can't be considered as extra space;

// Above is for LeftView, for RightView we just swap the "statement #1" & "statement #2"
// if we want to just print the Left/Right view then we can just maintain a max_level variable instead of extra DS.
