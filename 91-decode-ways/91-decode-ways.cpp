class Solution {
public:
    int numDecodings(string s) {
        
        // Two choices:
        //      1. Take only one digit
        //      2. Take two digits
        // The current action will change the result => Dynamic Programming (X greedy)
        unordered_map<string, int> um;
        return helper(s, um);
    }
    int helper(string s, unordered_map<string, int>& um){
        if(um.find(s) != um.end()) return um[s];
        
        // if first digit equals to 0 return 0 (dead)
        if(s[0] == '0') return 0;
        
        if(s.length() <= 1) return 1;

        // if first digit is greater than 2, can take only 1 digit
        if(s[0] > '2' || s[0] == '2' && s[1] > '6' ){
            return um[s] = helper(s.substr(1, s.length()), um);
        }
        
        return um[s] = helper(s.substr(1, s.length()), um) + helper(s.substr(2, s.length()), um);

    }
};