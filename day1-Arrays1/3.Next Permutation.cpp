void nextPermutation(vector<int>& nums) {
        
        // next_permutation(nums.begin(),nums.end());--> in-built 
        // no need to handle edge-case, defaultly next_permutation returns "123" for "321". 
        
        int i=nums.size()-2;
        
        // for( ; i>=0;i--) if(nums[i]<nums[i+1]) break;
        
        while( i>=0 && nums[i]>=nums[i+1]) i--;
        
        // observe here there is a slight difference b/w for & while loops 
        
        if(i >= 0){
            int j=nums.size()-1;
            while(nums[i] >= nums[j]) 
                j--;
            swap(nums[i],nums[j]); // in-built 
        }
        reverse(nums.begin()+i+1,nums.end()); // in-built
    }
// Time : O(n) ,Space : O(1)

// intuition behind this algorithm is just note down some observations
// how one permutation is getting changed to next-one.