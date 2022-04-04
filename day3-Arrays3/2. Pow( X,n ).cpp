class Solution {
public:
    
    // Range of Int : -2,147,483,648 to 2,147,483,647
    double myPow(double x, int n) {
         
        double ans = 1.0;
        // Edge Case bcz if (-2,147,483,648*-1) stored in INT , it gets overflown.
        // So store in Long Long
        long long abs_of_n = n<0 ? (long long)n * -1 : n;
        
        while(abs_of_n > 0){
            if(abs_of_n % 2 == 0){
                x = x * x;
                abs_of_n = abs_of_n / 2;
            }   
            else{
                ans = ans * x;
                abs_of_n = abs_of_n - 1;
            }
        }
        if(n<0) ans= (double)1.0 / ans;
        return ans;
    }
};
// Time Comp: O(log n) , where n is power in X^n

// for Brute Force approach timeComplexity : O(n) where n is power in X^n
// bcz we need to run a loop from 1..n in brute Force approach.
