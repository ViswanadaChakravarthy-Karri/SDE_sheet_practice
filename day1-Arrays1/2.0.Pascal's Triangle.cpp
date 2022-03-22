vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back({1});
        numRows--;
        while(numRows--){
            vector<int> v;
            int k=triangle.size()-1;
            for(int i=-1,j=0; j<=triangle[k].size() ;i++,j++){
                int temp=0;
                if(i>=0)    temp += triangle[k][i];
                if(j<=triangle[k].size()-1)  temp += triangle[k][j];
                v.push_back(temp);
            } 
            triangle.push_back(v);
        }
        return triangle;
    }