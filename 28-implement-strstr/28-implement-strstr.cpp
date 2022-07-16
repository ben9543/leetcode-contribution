class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0 || haystack.length()==0) return 0;
        for (int i = 0; i < haystack.length(); i++){
            int aptr = i;
            int bptr = 0;
            int count = 0;
            
            while(haystack[aptr] == needle[bptr] && aptr < haystack.length() && bptr < needle.length()){
                aptr++;
                bptr++;
                count++;
            }
            if(count == needle.length())return i;
        }
        return -1;
    }
};