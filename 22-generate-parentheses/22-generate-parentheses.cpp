class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", n, n);
        return res;
    }
    
    void helper(vector<string>& res, string s, int open, int close){
        if(!open && !close){
            res.push_back(s);
            return;
        }
        if(open > close || open < 0 || close < 0) return;
        else{
            string tmp1 = s+'(';
            helper(res, tmp1, open-1, close);
            string tmp2 = s+')';
            helper(res, tmp2, open, close-1);
        }
    }
};