// Solution 1: Brute Force

// Approach:
// At every index, we make a decision whether to pick or not pick the element at that index. 
// This will help us in generating all possible combinations but does not take care of the duplicates. 
// Hence we will use a set to store all the combinations that will discard the duplicates.

// Time Complexity: O( 2^n *(k log (x) )). 2^n  for generating every subset and k* log( x)  to insert every combination of average length k in a set of size x. 
//                  After this, we have to convert the set of combinations back into a list of list /vector of vectors which takes more time.

// Space Complexity:  O(2^n * k) to store every subset of average length k. Since we are initially using a set to store the answer another O(2^n *k) is also used.
   
// Solution 2: Optimal

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
