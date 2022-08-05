#include <cmath>
class Solution {
public:
    int reverse(int x) {
        
        int res = 0;
        while(x)
        {
            int digit = x%10;
            x = x/10;
            
            if(res > INT_MAX/10 || (res== INT_MAX/10 && digit > INT_MAX%10))
                return 0;
            else if(res < INT_MIN/10 || (res == INT_MIN/10 && digit < INT_MIN%10))
                return 0;
            else{
                
                // Reversing integer
                res = (res*10) + digit;
            }
        }
        return res;
    }
};