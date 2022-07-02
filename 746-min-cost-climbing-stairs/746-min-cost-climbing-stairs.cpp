#include <map>
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        map<int, int> m;
        return min(minCost(n-1, cost, m), minCost(n-2, cost, m));
    }
    int minCost(int i, vector<int> cost, map<int, int>& m){
        if(i < 0) return 0;
        if (i == 0 || i == 1) return cost[i];
        
        if(m.find(i) != m.end())return m[i];
        m[i] = cost[i] + min(minCost(i-1, cost, m), minCost(i-2, cost, m));
        return m[i];
    }
};