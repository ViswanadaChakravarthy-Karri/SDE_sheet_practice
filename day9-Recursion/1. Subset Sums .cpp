class Solution
{
public:
    void func(vector<int>& arr,int N,vector<int>& sumSubset,int sum)
    {
        if(N<0)
        {
            sumSubset.push_back(sum);
            return;
        }
        // pick-up the curr index
        func(arr,N-1,sumSubset,sum+arr[N]);
        
        // do not pick-up the curr index
        func(arr,N-1,sumSubset,sum);
        
        return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sumSubset;
        func(arr,N-1,sumSubset,0);
        sort(sumSubset.begin(),sumSubset.end());
        return sumSubset;
    }
};
// Time: O(2^N) for Recursion-calls + O( 2^N * log(2^N) ) for sorting
// Space: O(2^N) for sumSubset + O(N) for Recursion calls
