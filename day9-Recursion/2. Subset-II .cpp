class Solution {
private:
    void findSubsets(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
         ans.push_back(ds);
         for (int i = ind; i < nums.size(); i++) {
            // while(i!=ind && i<nums.size() && nums[i]==nums[i-1]) i++; --> why failing..?
            if (i != ind && nums[i] == nums[i - 1])  continue;  // but its working...!!!
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ans);
            ds.pop_back();
         }
      }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        findSubsets(0,nums,ds,ans);
        return ans;
    }
};
// Time : O(2^N)for rec-calls * O(N) to store in ds
// Space: O(2^N) for ans[][] + O(N) for Rec-calls
