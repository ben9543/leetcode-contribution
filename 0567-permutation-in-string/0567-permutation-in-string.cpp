class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> c1(26,0);
        vector<int> c2(26,0);
        int matches = 0;
        if(s1.length() > s2.length()) return false;
        for(int i = 0; i < s1.length(); i++){
            c1[s1[i]-'a']++;
            c2[s2[i]-'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(c1[i] == c2[i])matches++;
        }
        int left = 0;
        for(int j = s1.length(); j < s2.length(); j++){
            if(matches == 26)return true;
            int r_index = s2[j] - 'a';
            c2[r_index]++;
            if(c1[r_index]==c2[r_index])matches++;   // Matches
            else if(c1[r_index]+1==c2[r_index])matches--; // Mismatch && previously matched
            
            int l_index = s2[left] - 'a';
            c2[l_index]--;
            if(c1[l_index]==c2[l_index])matches++;
            else if(c1[l_index]-1==c2[l_index])matches--;
            left++;
        }
        return (matches==26);
    }
};