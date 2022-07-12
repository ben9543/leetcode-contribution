#include <cmath>
class Solution {
public:
    int reverse(int x) {
        vector<int> stack;
        int res = 0;
        int count = 0;
        bool isPos = true;
        
        
        // Base case
        if (x < 10 && x > -10) return x;
        if (x >= INT_MAX || x <= INT_MIN) return 0;

        if(x < 0){
            x *= -1;
            isPos = false;
        }
        
        while(x){
            stack.push_back(x%10);
            x = floor(x/10);
        }
        
        // Create the integer value
        while(!stack.empty()){
            if ( (res/10 + stack.back() * pow(10, count)/10  > INT_MAX/10) ) return 0;
            else if( (res/10 + stack.back() * pow(10, count)/10  == INT_MAX/10) && (res%10 > INT_MAX%10) )return 0;
            res += (stack.back() * pow(10, count));
            stack.pop_back();
            count++;
        }
        
        return (isPos ? res : res*-1);
    }
    
    bool willOverflow(int x, int y){
        cout << x << "," << y << endl;
        return ((x + y >= INT_MAX/10) && (x%10 > INT_MAX%10));
    }
};