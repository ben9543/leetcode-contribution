class Solution {
    
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hm;
        for(auto c : s){
            if(hm.find(c) != hm.end())
                hm[c]++;
            else
                hm[c] = 1;
        }
        
        for(auto c : t){
            if(hm.find(c) == hm.end())
                return false;
            else
                hm[c]--;
            
            if(hm[c] == 0)
                hm.erase(c);
        }
        
        return (hm.size()==0);
    }
};