class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> c1(26,0);
        vector<int> c2(26,0);
        int matches = 0;
        
        if(s1.length() > s2.length()) return false;
        
        // Counting number of character occurrence
        for(int i = 0; i < s1.length(); i++){
            c1[s1[i]-'a']++; 
            c2[s2[i]-'a']++; 
        }
        
        for(int i = 0; i < 26; i++){
            if(c1[i] == c2[i])matches+=1;
        }
        int left = 0;
        for(int right = s1.length(); right < s2.length(); right++){
            
            // Base case
            if(matches == 26)return true;
            
            /* Right (add) */
            int r_index = s2[right]-'a';
            c2[r_index]++;
            
            // After update c2 count, check if the current character's count are the same in both c1 and c2
            // If those two matches, that means now we have one more match.
            if(c1[r_index] == c2[r_index])matches++;
            
            // If previously the counts matched, we need to decrement matches.
            // This is why we are only checking c1[index] + 1 case. If c1[index] and c2[index] previously matched, c1[index] will always strictly greater than c2[index] by one.
            else if(c1[r_index] + 1 == c2[r_index])matches--;
            
            /* Left (delete) */
            int l_index = s2[left]-'a';
            c2[l_index]--;
            if(c1[l_index] == c2[l_index])matches++;
            else if(c1[l_index] - 1 == c2[l_index])matches--;
            left++;
            
        }
        return (matches == 26);
    }
};