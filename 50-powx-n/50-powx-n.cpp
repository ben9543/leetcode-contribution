class Solution {
public:
    double myPow(double x, int n) {
        double res = helper(x, abs(n));
        return (n >= 0) ? res : 1/res;
    }
    
    double helper(double x, int n){
        if(n == 0)return 1;
        if(x == 0)return 0;
        
        // Get the other half's solution
        double res = helper(x, n/2);
        
        // Multiply by itself
        res *= res;
        
        // Multiply addtional x if n is odd
        return (n%2 != 0) ? (x * res) : res;
    }
};