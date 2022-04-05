class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> hashSet(nums.begin(),nums.end()); // O(n)
        int count=0;
        for(int i=0; i<nums.size() ; i++){ // O(n)
            if(hashSet.find(nums[i]-1)==hashSet.end()){
                int j=nums[i];
                while(hashSet.find(j)!=hashSet.end()) ++j;  // cummulative complexity : O(n)
                count = max(count,j-nums[i]);
            }
        }
        return count;
    }
};
// Time Complexity : O(n + n + n) = O(n) , Space Complexity: O(n)
