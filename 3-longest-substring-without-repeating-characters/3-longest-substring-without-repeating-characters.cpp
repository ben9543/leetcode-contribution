#include <map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int aptr = 0;
        int maxLen = 0;
        unordered_map<char, int> hm;
        // Sliding window
        // [////{    ]   }
        // expand the window
        // if the repeating charater is found, update the maxLen
        // also update the hashmap & aptr
        // if aptr is less than the value(index) stored in the hashmap, update aptr as the stored value
        // else update the hashmap
        
        for(int bptr = 0; bptr < s.length(); bptr++)
        {
            if(hm.find(s[bptr]) == hm.end()) hm[s[bptr]] = bptr;
            else{
                if(hm[s[bptr]] >= aptr){
                    aptr = hm[s[bptr]] + 1;
                }
                hm[s[bptr]] = bptr;
            }
            maxLen = max(maxLen, bptr - aptr + 1);
        }
        
        return maxLen;
    }
};