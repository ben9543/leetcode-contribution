class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int maxFreq = 0;
        int l = 0;
        unordered_map<char, int> hm;
        
        for (int r = 0; r < s.length(); r++)
        {
            char c = s[r];
            // Add elements' frequency to the hashmap
            if(hm.find(c) == hm.end()) hm[c] = 1;
            else hm[c]++;
            
            // Update the max frequency
            maxFreq = max(maxFreq, hm[c]);
            
            // If current window is invalid, increase left pointer
            // Before move the left pointer, decrease the count from the hashmap
            while(r - l + 1 - maxFreq > k){
                hm[s[l]]--;
                l++;
            }
            
            // Update the maxLen
            maxLen = max(maxLen, (r - l + 1));
        }
        return maxLen;
    }
};
