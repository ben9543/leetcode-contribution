class Solution {
public:
    bool isSubsequence(string s, string t) {
        int aptr = 0, bptr = 0;
        while(bptr < t.length()){
            if(s[aptr] == t[bptr]){
                aptr++;
            }
            bptr++;
        }
        return aptr == s.length();
    }
};