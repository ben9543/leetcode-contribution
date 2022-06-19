class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> stack1;
        vector<char> stack2;
        
        for (char c: s){
            if(c != '#'){
                stack1.push_back(c);    
            } else {
                if (!stack1.empty())
                    stack1.pop_back();   
            }
        }        
        for (char c: t){
            if(c != '#'){
                stack2.push_back(c);    
            } else {
                if (!stack2.empty())
                    stack2.pop_back();   
            }
        }
    
        while (!stack1.empty() && !stack2.empty()){
            //cout << stack1.pop_back() << ":" << stack2.pop_back() << endl;
            if (stack1.back() != stack2.back())
                return false;
            stack1.pop_back();
            stack2.pop_back();
        }
        if (stack1.empty() == stack2.empty())
            return true;
        else
            return false;
    }
};