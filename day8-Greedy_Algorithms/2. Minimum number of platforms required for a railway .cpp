class Solution_2{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int std_timing(int time)
    {
        if(time%100 >= 60)
        {
            time += 40; // -60 +100
        }
        return time;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
        map<int,int> mpp;
        for(int j=0;j<n;j++)
        {
            mpp[std_timing(arr[j])]++;
            mpp[std_timing(dep[j]+1)]--;
        }
        int max_no_of_platforms_used=0,curr_platform_in_use=0;
        for(auto it:mpp)
        {
            curr_platform_in_use += it.second;
            max_no_of_platforms_used = max (max_no_of_platforms_used,curr_platform_in_use);
        }
        // min_platforms_req to solve problm is max_no_of_platforms_used at any PointOfTime.
        return max_no_of_platforms_used;
    }
    // Time Complexity: O(nLogn)
    // Auxiliary Space: O(n)
};


class Solution_3{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int std_timing(int time)
    {
        if(time%100 >= 60)
        {
            time += 40; // -60 +100
        }
        return time;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
        int mpp[2361]={0};
        for(int j=0;j<n;j++)
        {
            mpp[std_timing(arr[j])]++;
            mpp[std_timing(dep[j]+1)]--;
        }
        // min_platforms_req to solve problm is max_#platforms_used at any PointOfTime.
        int max_no_of_platforms_used=0,curr_platform_in_use=0;
        for(int k=0;k<2361;k++)
        {
            curr_platform_in_use += mpp[k];
            max_no_of_platforms_used = max (max_no_of_platforms_used,curr_platform_in_use);
        }
        return max_no_of_platforms_used;
    }
    // Time Complexity: O(n) bcz we are using direct hashing
    // Auxiliary Space: O(1) auxilary space will always req following size ( 0000 ≤ A[i] ≤ D[i] ≤ 2359 )
};
