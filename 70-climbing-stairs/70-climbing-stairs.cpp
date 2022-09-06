class Solution {
public:

    unordered_map<int, int> m;
    
    int climbStairs(int n) {

        return helper(n);
    }
    
    int helper(int n){
        
        // us[i] = k
        //  => k ways get to i
        
        if(n < 0)return 0;
        if(n == 0)return 1;
        if(m.find(n) != m.end())return m[n];
        
        return m[n] = helper(n-1) + helper(n-2);
    } 
};