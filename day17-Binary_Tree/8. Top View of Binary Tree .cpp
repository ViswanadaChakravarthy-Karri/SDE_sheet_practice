// we can do using Reverse Level order: time= O(#nodes) & space= O(#nodes)[for queue] + O(#nodes)[for stack]
// But we can solve using Level order: time= O(#nodes) & space= O(#nodes)[for queue]. ----> ( w/o stack )

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> res;
        if(root==NULL)
            return res;
            
        map<int,int> mpp;
        queue<pair<Node*,int>> q; //node,index
        
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int> pr=q.front();
            q.pop();
            
            Node *curr=pr.first;
            int index=pr.second;
            
            if(mpp.find(index)==mpp.end())
                mpp[index]=curr->data;
            
            if(curr->left)
                q.push({curr->left,index-1});
            if(curr->right)
                q.push({curr->right,index+1});
        }
        
        for(auto i:mpp)
            res.push_back(i.second);
        return res;
    }

};
