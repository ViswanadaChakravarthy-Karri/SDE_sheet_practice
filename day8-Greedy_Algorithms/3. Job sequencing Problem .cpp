class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comparator(Job a,Job b) // must be static
    {
        return (a.profit>b.profit);
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comparator);
        int maxi=0;
        for(int i=0; i<n; i++)
            maxi= max(arr[i].dead,maxi);
            
        int dead[maxi+1];
        memset(dead,-1,sizeof(dead));
        
        int count_jobs=0,max_prof=0;
        for(int j=0; j<n; j++)
        {
            for(int k=arr[j].dead; k>0; k--)
            {
                if(dead[k]==-1)
                {
                    dead[k]=arr[j].id;
                    count_jobs += 1;
                    max_prof += arr[j].profit;
                    break;
                }
            }
        }
        return {count_jobs,max_prof}; // bcz return type: vector<int>
    }
//   TC: O(nlogn) + O(n * m)
//   SC: O(m)
};
