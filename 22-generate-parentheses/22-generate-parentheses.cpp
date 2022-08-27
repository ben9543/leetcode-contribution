class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", n, n);
        return res;
    }
    
    void helper(vector<string>& res, string s, int open, int close){
        // count stands for how many open paranthesis are used so far
        
        // If close is less than open, return function (invalid)
        if(open > close)return;
        
        // If open is zero, append close until it gets to zero and then return it
        if(open == 0){
            while(close){
                s+=")";
                close--;
            }
            res.push_back(s);
            return;
        }
        helper(res, s+"(", open-1, close);
        helper(res, s+")", open, close-1);
    }
};