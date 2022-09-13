class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> pcount(26, 0);
        vector<int> scount(26, 0);
        
        int aptr = 0;
        int bptr = p.length()-1;
        vector<int> res;
        
        if(s.length() < p.length())return {};
        
        for(int i = 0; i < p.length(); i++){
            pcount[(p[i]-'a')]++;
            scount[(s[i]-'a')]++;
        }
        
        while(bptr < s.length())
        {
            if(checkAnagram(scount, pcount)){
                res.push_back(aptr);
            }
            
            scount[s[aptr]-'a']--;
            aptr++;
            bptr++;
            if(bptr < s.length())
                scount[s[bptr]-'a']++;
        }
        
        return res;
    }
    
    bool checkAnagram(vector<int>& scount, vector<int>& pcount){
        for(int i = 0; i < 26; i++)
        {
            if(scount[i] != pcount[i])return false;
        }
        return true;
    }
};