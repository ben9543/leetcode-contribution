#include <vector>
#include <cmath>
class Solution {
public:
    string decodeString(string s) {
        // Planning
        // createString: Recrusive function that creates the complete string encoded_string
        // extractNum: Returns the integer value for k
        int index = 0;
        string res = "";
        while (index < s.length()){
            if(isdigit(s[index])){
                res += createString(s, index);
                index++;
            } else {
                res += s[index];
                index++;
            }
        }
        return res;
    }
    string createString(string s, int& index){
        int num = extractNum(s, index);
        string res = "";
        string temp = "";
        
        index++; // skip the first closing bracket
        
        // Start the loop
        while(s[index] != ']'){
            if(isdigit(s[index])){
                temp += createString(s, index);
                index++; // skip the last closing bracket
            } else {
                temp += s[index];
                index++;
            }
        }
        for (num; num > 0; num--){
            res = res+temp;
        }
        return res;
    }
    int extractNum(string s, int& index){
        int res = 0;
        string temp = "";
        while(isdigit(s[index])){
            temp+=s[index];
            index++;
        }
        int power = temp.length()-1;
        for (auto c: temp){
            res += ( (c-'0')*pow(10, power) );
            power--;
        }
        return res;
    }
};