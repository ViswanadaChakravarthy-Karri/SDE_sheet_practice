class Solution_1{ // best intuition , to use in interview w/o extra space...!!😳
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // Pairs cannot be together. Thats the problem. Just think yourself as a station master, 
        // and you just care how many came and how many went. Not when one came and when went
        sort(arr,arr+n);
        sort(dep,dep+n);
        int plat_needed=1, result=1;
        // atleast one train will occupy plat, so starting from start_ind( i ) = 1 
        int i=1,j=0; 
        while(i<n && j<n)
        {
            if(arr[i]<=dep[j]) // train_arrival
            {
                plat_needed++;
                i++;
            }
            else // train_departure
            {
                plat_needed--;
                j++;
            }
            if(plat_needed > result)
                result = plat_needed;
        }
        return result;
     }
//     Time: O(nlogn) for sorting
//     space: O(1)
};

class Solution_2{ // here both soln's uses intuition of chocolate_dstribution problem from HackerRank which requires extra space
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
    int findPlatform_1(int arr[], int dep[], int n)
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
    // Time Complexity: O(nLogn) bcz of map
    // Auxiliary Space: O(n) bcz of map
    
    int findPlatform_2(int arr[], int dep[], int n)
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
    // But in general treat Space as O(n) , to use same approach in other problems as well
};
