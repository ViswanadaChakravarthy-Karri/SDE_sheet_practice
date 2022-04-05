class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans{0,0};
        unordered_map<int,int> um;
        for(int i=0 ; i<nums.size() ; i++){
            if(um[target-nums[i]]!=0){
                ans[0] = i;
                ans[1] = um[target-nums[i]];
                // decoding the conflict , if necessary
                if(ans[1]==-1) ans[1] = 0; 
            }
            else if(um[nums[i]]==0){
                um[nums[i]]=i;
                if(i==0) um[nums[i]] = -1; 
                // we are encoding ind '0' as -1 bcz default value for any key in um is '0'
                // which will be a conflict
            }   
        }
        return ans;
    }
};
// Time complexity: O(n) , Space Complexity: O(n)
// in Worst case unordered_map doesn't work in O(1)
// then go with ordered_map --> which take O(log n),
// then Total Complexity would become O(n logn)
