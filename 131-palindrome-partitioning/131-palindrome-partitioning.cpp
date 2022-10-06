class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        helper(0, s, vector<string>());
        return res;
    }
    
    void helper(int start, string s, vector<string> curr){
        if(start >= s.length()){
            res.push_back(curr);
            return;
        }
        for (int j = start+1; j <= s.length();j++){
            string c = string(s.begin()+start, s.begin()+j);
            cout << c << endl;
            if(isPalindrome(c)){
                curr.push_back(c);
                helper(j, s, curr);
                curr.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s){
        return (s == string(s.rbegin(), s.rend()));
    }
};