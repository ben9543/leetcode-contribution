bool isSubseq(string s, string input){
	int aPtr = 0, bPtr = 0;
    while(aPtr < s.length()){
    	if (bPtr >= input.length()) return true;
    	if(s[aPtr] == input[bPtr]){
            bPtr++;
        }
            aPtr++;
        }
        return false;
    }

string findLongestWord(string s, vector<string> d){
	string max = "";
    for (string str: d){
    	if (max.length() < str.length() && isSubseq(s, str)){
    		max = str;
        }
    }
    return max;
}
