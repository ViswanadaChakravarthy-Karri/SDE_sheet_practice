/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        map<int,map<int,multiset<int>>> nodes; 
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto pr=q.front();
            q.pop();
            TreeNode* node=pr.first;
            int line=pr.second.first;
            int level=pr.second.second;
            nodes[line][level].insert(node->val);
            
            if(node->left)
                q.push({node->left,{line-1,level+1}});
            if(node->right)
                q.push({node->right,{line+1,level+1}});
        }
        for(auto it1: nodes){ // traversing over map<int,map<int,multiset<int>>>
            vector<int> tmp;
            for(auto it2:(it1.second)) // traversing over map<int,multiset<int>>
            { 
                // inserting all elements of multiset<int> which are defaultly sorted, at end of tnp
                tmp.insert(tmp.end(),it2.second.begin(),it2.second.end()); 
            }
            res.push_back(tmp);
        }
        return res;
    }
};
