class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // idea: dp[4] = true means
        //      substring from first character to the fourth character can be segmented
        unordered_set<string> us;
        
        // To avoid linear search
        for(auto word : wordDict){
            us.insert(word);
        }
        
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;
        
        for(int i = 0; i <= s.length(); i++){
            
            for(int j = i; j <= s.length(); j++){
                if(dp[i]){
                    string cand = s.substr(i, j-i+1);
                    cout << i <<"," << j-i+1  <<"\t" << cand << endl;
                    if(us.find(cand) != us.end()){
                        dp[j+1] = true;
                    }
                }
            }
        }
        return dp[s.length()];
    }
};