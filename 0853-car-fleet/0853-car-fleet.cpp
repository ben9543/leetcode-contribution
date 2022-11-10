class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, int>> v;
        vector<float> s;
        
        for (int i = 0; i < position.size(); i++){
            v.push_back({position[i], speed[i]});
        }
        
        sort(v.begin(), v.end());
        
        for(int i = v.size()-1; i>=0; i--){
            s.push_back((float)(target - v[i].first) / v[i].second);
            
            // Since we are checking the stack in reverse order, we can just check
            // the car right behind 
            
            if(s.size() >= 2 && s[s.size()-1] <= s[s.size()-2]){
                s.pop_back();
            }
        }

        return s.size();
    }
};