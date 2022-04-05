// Both 4.0 and 4.1 are implemented , with a small difference --> make an observation on that

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> hash;
        
        int length=0, sum=0;
        
        hash[0]=-1 ; // since we are not standing at any index, assume it as zero
        // there's an reason also while calculating length this '-1' helps
        // in calculating the length accurately....
        
        for(int i=0 ; i<n ; i++){
            sum += A[i];
            if(hash.find(sum)==hash.end()) hash[sum]=i;
            else                           length = max(length,i-hash[sum]);
        }
        return length;
        
    }
};
// Time complexity: O(n) bcz for unordered_map->avg tc is O(1) for any operation
// Space complexity: O(n) in worst case & average
