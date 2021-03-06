class Solution {
public:
      
    int majorityElement(vector<int>& nums) {
        int count=0, maj;
        
        for(int i=0; i<nums.size() ; i++){
            // we are assuming the starting element as Maj , if count is 0
            if(count==0){
                // bcz we assume, before this count(maj) is balanced with count(others)
                maj=nums[i];
                count=1;
            }
            else{
                if(nums[i]==maj) count ++;
                // we increasing the count of Maj element
                else count--;
                // Balancing the count of majority elements with Other elements.
            }
        }
        return maj;
    }
};
// Time Complexity: O(n) Space Complexity : O(1)
// ******** Moore's Voting Algorithm *********
// Main intuition behind this algorithm is Majority element occurs >floor(N/2) times , where N: size of arr
