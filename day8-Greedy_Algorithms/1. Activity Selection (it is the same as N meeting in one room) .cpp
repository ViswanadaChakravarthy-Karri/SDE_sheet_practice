class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    // static bool sortBySecond(const pair<int,int> &a, const pair<int,int> &b)
    // {
    //     return (a.second < b.second);
    // }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
            v.push_back({start[i],end[i]});
        //sort(v.begin(),v.end(),sortBySecond);
        // we can use above comparator(must be static) func 
        // or Lambda func like below....
        sort(v.begin(),v.end(),
        [](const pair<int,int> a,const pair<int,int> b){
            return (a.second<b.second);
        });
        int curr_time=-1;
        int count=0;
        for(int j=0;j<v.size();j++)
        {
            if(v[j].first > curr_time)
            {
                count++;
                curr_time = v[j].second;
            }
        }
        return count;
    }
  // time: O(nlogn) for sort 
  // Space: O(n) for_sort/vector<pairs>
};
