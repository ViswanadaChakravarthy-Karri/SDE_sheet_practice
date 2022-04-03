pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{

  int mmr=0, m2mr2=0; // mnr: m-r & m2mr2: sq(m)-sq(r)
    for(int i=0; i<n ; i++){
        mmr += i+1 - arr[i];
        m2mr2 += (i+1)*(i+1) - (arr[i]*arr[i]);
    }
    int mpr=0; // mpr: m+r
    mpr = m2mr2 / mmr;
    pair<int,int> ans; // 1st: Missing num , 2nd: Repeated num
    ans.first = (mpr + mmr) / 2;
    ans.second = (mpr)-ans.first;
    return ans;
}

