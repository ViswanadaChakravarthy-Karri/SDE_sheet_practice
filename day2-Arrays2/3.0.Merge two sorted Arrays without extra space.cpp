 int nextGap(int gap){
            if(gap<=1)
                return 0;
            return (gap/2) + (gap%2);
        }
void merge(long long arr1[], long long arr2[], int n, int m) 
{ 
           int gap= n + m;
           int i,j;
            
           for (gap = nextGap(gap) ; gap > 0; gap = nextGap(gap))
           {
                // for(i=0,j=gap ; j<m ; i++,j++)
                // {
                //     if(i<n && j<n)      swap(arr1[i] , arr1[j]);
                //     else if(i<n && j>=n)     swap(arr1[i] , arr2[j-n]); ----> why not working???? bcz i'm sorting w/o comparing elements
                //     else if(i>=n && j>=n)    swap(arr2[i-n] , arr2[j-n]);
                // }
                
                for(i=0 ; i+gap < n ; i++) if(arr1[i]>arr1[i+gap]) swap(arr1[i],arr1[i+gap]);
                
                for(j= gap>n ? gap-n :0 ; i<n && j<m ; j++,i++) if(arr1[i]>arr2[j]) swap(arr1[i],arr2[j]);
                
                if(j<m) for(j=0 ; j+gap < m ;j++) if(arr2[j]>arr2[j+gap]) swap(arr2[j],arr2[j+gap]);
           }
             
} 

// Time : O(logn * n) here nextGap() gets called "log(n)" times and traversing takes "O(n)".
