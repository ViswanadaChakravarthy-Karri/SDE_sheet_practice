class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,pair<int,int>> hash;
        
        int length=0, sum=0;
        
        hash[0].first=-1, hash[0].second=-1; 
        // bcz we are storing curr & prev ind in map, while calc length.
        
        for(int i=0 ; i<n ; i++){
            sum += A[i];
            if(hash.find(sum)==hash.end()){
                hash[sum].first=i;
                hash[sum].second=-1;
            }
            else{
                hash[sum].second=i;
                length = max(length,i-hash[sum].first);
            }
        }
        return length;
        
    }
};
// Time Complexity : O(n), Space Complexity: O(n)
