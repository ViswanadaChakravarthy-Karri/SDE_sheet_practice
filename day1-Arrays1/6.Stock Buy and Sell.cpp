int maxProfit(vector<int>& prices) {
        int maxi=0;
        int n=prices.size();
        vector<int> temp(n);
        for(int i=n-1;i>=0;i--){
            temp[i]=maxi;
            maxi=max(maxi,prices[i]);
        }
        int maxPro=0;
        for(int i=0;i<n;i++)
        {
            if(prices[i] < temp[i])
                maxPro=max(maxPro,temp[i]-prices[i]);        
        }   
        // it is same even if merge these two loops.
        return maxPro;
    }