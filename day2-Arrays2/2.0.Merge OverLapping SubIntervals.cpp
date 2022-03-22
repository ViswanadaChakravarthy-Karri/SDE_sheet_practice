 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> res;
        
        // edge case --> v.v.imp
        if(intervals.size()==0){
            return res;
        }
        
        sort(intervals.begin(),intervals.end());

        stack<int> s;
        for(vector<int> p:intervals){
           
            // before accesing top of stack ,need to check if its empty
            if(!s.empty() &&s.top() < p[0]){
                    vector<int> temp(2);
                    temp[1]=s.top();
                    s.pop();
                    temp[0]=s.top();
                    s.pop();
                    res.push_back(temp);
                    
            }
            if(s.empty()){
                s.push(p[0]);
                s.push(p[1]);
            }
            else{
                int _top=s.top();
                s.pop();
                // we need to check whether 'p'is completely merged in the current interval from stack....???
                _top<p[1] ? s.push(p[1]) : s.push(_top);
            }   
        }
	// adding last pair to our data structure from stack..
         vector<int> temp(2);
         // add an edge case for intervals.size()==0 at the start,otherwise we might get an error here....!
         temp[1]=s.top();
         s.pop();
         temp[0]=s.top();
         s.pop();
         res.push_back(temp);
                    
        return res;
    }