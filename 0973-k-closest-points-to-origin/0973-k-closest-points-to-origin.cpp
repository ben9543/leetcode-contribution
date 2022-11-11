class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > pq;
        
        for(int i = 0; i < points.size(); i++){
            int p = pow(points[i][0],2) + pow(points[i][1],2);
            pq.push({p,i});
        }
        
        while(k){
            res.push_back(points[pq.top().second]);
            pq.pop();
            k-=1;
        }
        
        return res;
    }
};