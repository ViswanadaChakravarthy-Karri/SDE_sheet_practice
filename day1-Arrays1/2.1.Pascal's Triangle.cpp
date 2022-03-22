vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> r(numRows);
        
        for(int i=0;i<numRows;i++){
            r[i].resize(i+1);
            r[i][0]=r[i][i]=1;
            
            for(int j=1;j<i;j++){
                r[i][j] = r[i-1][j-1]+r[i-1][j];
            }
        }
        return r;
    }
// here Time : O(n^2) Space:O(n^2)

// Model_2: in Pascal's Triangle if row,column are given then print that value
// formula is C(row-1,column-1) --> Time : O(n) Optimised and Space:O(1)

// Model_3: in Pascal's Triangle if row number is given then print entire row
// we can do this using that formula for every element might increase complexity
// O(n^2) n--> for traversal and n--> for generating number from formula.

// for(int i=0;i<k;i++) { -->O(n)
//	res *= (n-i); 	  -->O(1)
//	res /= (i+1); 	  -->O(1)
//} --> in every iteration will get an element required

//Time: O(n)*O(1) , O(n)--> to traverse every column and O(1) to calculate element
//Space:O(n)--> for the generated row