class Solution {
public:
    int characterReplacement(string s, int k) {
        
        // 1. Store elements count in the hash map
        // 2. Get the maximum count from the hash map (O(n))
        // 3. bptr - aptr -maximumCount >= k suggests we can replace k number of characters and still get the unbroken streak
        
        
        int maxLen = 0;
        int maxFreq = 0;
        int low = 0;
        unordered_map<char, int> hm;
        
        for(int i = 0; i < s.length(); i++){
            char curr = s[i];
            if(hm.find(curr) == hm.end())hm[curr] = 1;
            else hm[curr]++;
            
            maxFreq = max(maxFreq, hm[curr]);
            
            while(i - low + 1 - maxFreq > k){
                hm[s[low]]--;
                low++;
            }
            maxLen = max(maxLen, i - low + 1);
        }

        return maxLen;
    }
    
    /*int longestCount(unordered_map<char, int> hm){
        int maximum = 0;
        for (auto p : hm){
            if(p.second > maximum)
                maximum = p.second;
        }
        return maximum;
    }*/
};