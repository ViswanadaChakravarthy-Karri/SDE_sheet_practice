class Solution {
private:
    void findCombination(vector<int>& candidates, int ind, int target, vector<vector<int>>& ans, vector<int>& ds)
    {
        if( target == 0 ){
            ans.push_back(ds); 
            return;
        }
        if( ind == candidates.size() || target < 0) 
            return ;
        int ele = candidates[ind];
        ds.push_back(ele);
        findCombination(candidates,ind,target-ele,ans,ds);
        ds.pop_back();
        findCombination(candidates,ind+1,target,ans,ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findCombination(candidates, 0, target, ans, ds);
        return ans;
    }
// Time: O(2^t) for Rec-calls * O(k) for copying DS, where n is candidates.size() & O(2^n) is O(2^t)
// Space: Unpredictable depth of stack bcz we are choosing a coin unknown #times.
};
