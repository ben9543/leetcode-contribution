#include <map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();
        
        int maxLen = 0;
        map<char, int> seen;
        int aPtr = 0;
        for (int bPtr = 0; bPtr < s.length(); bPtr++){
            char currChar = s[bPtr];
            if (seen.count(currChar) && (seen[currChar] >= aPtr)){
                aPtr = seen[currChar]+1;
            }
            maxLen = max(maxLen, bPtr - aPtr+1);
            seen[currChar] = bPtr;
        }
        return maxLen;
    }
};