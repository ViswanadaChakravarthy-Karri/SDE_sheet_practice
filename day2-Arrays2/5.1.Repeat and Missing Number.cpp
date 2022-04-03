int lsb(int xr){
        int res;
         while(xr!=0){
           res=xr;
           xr = xr & (xr-1);
       }
       return res;
    }
int *findTwoElement(int *arr, int n) {
       
       int xr=0,temp=0;
       for(int i=0 ; i< n ; i++) xr ^= arr[i] ^ (i+1) ;
      
       xr=lsb(xr);
        
       int a=0,b=0;
       for(int i=0;i<n;i++){
           if(arr[i] & xr ) a ^= arr[i] ;
           else             b ^= arr[i] ;
           
           if( i+1 & xr )  a ^= i+1;
           else          b ^= i+1;
       }
       
       int *res=(int*)malloc(sizeof(int)*2);
       for(int i=0;i<n;i++){
           
           // repeated number should be at first and then missing number.
           
           if(arr[i]==a){
               res[0]=a;
               res[1]=b;
               break;
           }
           else if(arr[i]==b){
               res[0]=b;
               res[1]=a;
               break;
           }
       }
       return res;
    }

// Time : O(n) , Space :O(1)

