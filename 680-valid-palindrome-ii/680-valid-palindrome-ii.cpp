class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0, end = s.length()-1;
        if (isPalindrome(start, end, s)){
            return true;
        } else {
            string left =  s.substr(0,start) + s.substr(start+1, end+1);
            string right = s.substr(0,end) + s.substr(end+1, s.length());
            int leftStart = 0, leftEnd = left.length()-1, rightStart = 0, rightEnd = right.length()-1;
            if (isPalindrome(leftStart, leftEnd, left) || isPalindrome(rightStart, rightEnd, right)){
                return true;
            }
        }

        return false;
    }
    
    bool isPalindrome(int& start, int& end, string s){

        while (start < end){
            
            char c1 = s[start];
            char c2 = s[end];
            
            if (c1 != c2){
                return false;
            }
            
            // Increase & decrease indices
            start+=1;
            end-=1;
        }
        return true;
    }
};