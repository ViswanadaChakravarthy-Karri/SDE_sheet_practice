class Solution {
public:
  
    int uniquePaths(int m, int n) {
        
        int N = m+n-2;
        int r = m-1; // r can also be m-1, anyhow result will be same 
        
        // try to make some observations ans is Combination( m-1 + n-1 , n-1 or m-1 )
        double result=1;
        for(int i=1 ; i<=r ; i++)
            result = result* (N-r+i) / i;
        // result = result* (N-i+1) / i; // --> but why this is not working😒
        return result;
    }
};
