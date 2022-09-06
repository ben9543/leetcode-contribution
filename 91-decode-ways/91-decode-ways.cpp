class Solution {
public:
    
    // key: from this key(index)
    // value: value many ways to decode
    unordered_map<string, int> m;
    
    int numDecodings(string s) {
        
        // Need to test to cases: taking 1 string & taking 2 strings
        
        return helper(s);
        
    }
    
    int helper(string s){
        
        // Base cases
        if(s[0] == '0')return 0;
        if(s.length() <= 1)return 1;
        if(m.find(s) != m.end()) return m[s];
        
        // We can take two chars at most
        if(s[0]=='1' || (s[0] =='2' && s[1] <= '6')){
            return m[s] = helper(s.substr(1,s.length()-1)) + helper(s.substr(2, s.length()-2));
        }
        
        return m[s] = helper(s.substr(1,s.length()-1));
    }
    
    
};