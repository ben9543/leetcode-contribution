class Solution {
    
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length())return false;
        
        unordered_map<char, int> mp;
        for (auto c : s){
            if(mp.find(c) == mp.end()){
                mp[c] = 1;
            } else {
                mp[c] = mp[c] + 1;
            }
        }
        
        for (auto m: mp){
            cout << m.first << m.second << endl;
        }
        
        for (auto c: t){
            if(mp.find(c) == mp.end()){ // not found
                return false;
            } else {
                mp[c] -= 1;
                if(mp[c] < 0) return false;
            }
        }
        
        for (auto m: mp){
            cout << m.first << m.second << endl;
           if( m.second != 0) return false;
        }
        
        return true;
    }
};