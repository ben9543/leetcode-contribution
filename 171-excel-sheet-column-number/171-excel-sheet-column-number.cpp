#include <cmath>
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int size = columnTitle.length();
        int count = 0;
        int exp = 0;
        for (int i = size-1; i >=0 ; i--){
            count += (columnTitle[i] - 64)*pow(26, exp);
            exp++;
        }
        return count;
    }
};