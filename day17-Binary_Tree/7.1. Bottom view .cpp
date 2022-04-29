class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> res;
        if(root==NULL)
            return res;
        map<int,int> mp;  //<index,value>  
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto pr=q.front();
            q.pop();
            Node *curr=pr.first;
            int index=pr.second;
            mp[index]=curr->data;
            if(curr->left)
                q.push({curr->left,index-1});
            if(curr->right)
                q.push({curr->right,index+1});
        }
        for(auto ele:mp){
            res.push_back(ele.second);
        }
        return res;
    }
};
// O(nlogn) time, O(n) space
