#include <cmath>
class Solution {
public:
    int titleToNumber(string columnTitle) {
        // 1. Understanding
        // Input: string 
        // Output: int
        // 2. Matching
        // Extracting a digit | bit from an integer
        // Loop, either for or while => For loop with backward looping 
        // Use ASCII table
        // 3. Planning
        // Backward loop is gonna start from the length of the string - 1 => we need to access the least significant digit => last element of the string.
        // 4. Implementing
        int l = columnTitle.length()-1;
        int result = 0;
        int count = 0;
        for (int i = l; i >= 0; i--){
            // 'A' => 65
            // 'A' - 64 = 1
            // 'ABC'
            int n = columnTitle[i] - 64; // C(67) - 64 => 3
            
            // Each digit represents 26
            result += (n * pow(26, count));
            count++;
        }
        return result;
    }
};