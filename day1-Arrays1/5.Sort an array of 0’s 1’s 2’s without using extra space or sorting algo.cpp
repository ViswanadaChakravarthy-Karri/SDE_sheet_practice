class Solution {
public:
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        
        while(mid <= high){
            switch(nums[mid]){
                case 0:
                    swap(nums[low],nums[mid]); 
                    mid++;
                    low++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[high],nums[mid]);
                    high--;
                    break;
            }
        }
        return;
    }
};

// here intuition is 3-Pointer approach 
// Time : O(n)