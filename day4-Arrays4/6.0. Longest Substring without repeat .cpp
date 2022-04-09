class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
        int i=0, j=0;
        int length=0;
        char h_t[256]={0};
        
        for( ;j<s.size() ; j++){
            while( h_t[(int)s[j]] == 1 ){
                h_t[(int)s[i]]=0;
                i++;
            }
            length = max( length, j-i+1 );
            h_t[(int)s[j]] = 1;
        }
        return length;
    }
};
// Time Complexity: O(n+n) , space complexity: O(1)

// 012345678
// pwbkewabc
// ans : 6
// i=3 , j=9 , length=6
// {kewabc}

// 1. check for charac
// 2. if found , move nxt NA place
// 3. store in hash-table

// bbbb --> worst case getting O(2n) time complexity
