class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> s;
        for(int i = 0; i < temperatures.size(); i++)
        {
            // If temperatures[i] is greater than top
            //      32, 33
            //      top i
            // We found warmer temp
            // Pop until find temperatures[i] that is warmer than s.top()
            while(!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};