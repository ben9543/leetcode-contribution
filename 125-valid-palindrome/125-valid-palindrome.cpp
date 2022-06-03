#include <algorithm>
class Solution {
public:
    bool isPalindrome(string s) {    
        vector<char> v;
        string result = "";
        
        // Trimming the string
        for (auto c : s){
            if (isalpha(c))result+=tolower(c);
            else if (isdigit(c))result+=c;
        }

        // Logic here
        int mid = floor(result.length()/2);
        for (int i = 0; i < mid; i++)
            v.push_back(result[i]);
        if (result.length()%2!=0) ++mid;
        for (int i = mid; i < result.length(); i++){
            if (v.back() != result[i])
                return false;
            else
                v.pop_back();
        }
        return true;
    }
};