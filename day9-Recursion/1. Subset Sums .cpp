class Solution
{
public:
    void solveSS(vector<int>& arr,int N,vector<int>& res,int sum=0)
    {
        if(N<0)
        {
            res.push_back(sum);
            return;
        }
        solveSS(arr,N-1,res,sum+arr[N]);
        solveSS(arr,N-1,res,sum);
        return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        solveSS(arr,N-1,res);
        return res;
    }
};
// Expected Time Complexity: O(2^N)
// Expected Auxiliary Space: O(2^N)
