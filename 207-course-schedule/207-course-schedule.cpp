class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int count = 0;
        vector<vector<int>> adjList(numCourses+1);
        vector<int> inDegree(numCourses,0);
        if(numCourses == 1 || numCourses == 0 || prerequisites.size() == 1) return true;
        
        // Initializing the data structures
        for (int i = 0; i < numCourses; i++)
            adjList.push_back(vector<int>());
        
        // Creating the data structures
        for (int i = 0; i < prerequisites.size(); i++){
            vector<int> pair = prerequisites[i];
            int to = pair[0];
            int from = pair[1];
            
            // Creating inDegree
            inDegree[to]+=1;
            //for (auto i : inDegree)cout << i << "\t";
            //cout << endl;
            
            
            // Creating adjList
            adjList[from].push_back(to);
        }
        
        //for (auto i : inDegree)cout << i << "\t";
        
        // From inDegree, find i with 0 in-degree
        vector<int> stack;
        for (int i = 0; i < inDegree.size(); i++){
            if (inDegree[i] == 0) {
                stack.push_back(i);
            };
        }
        while(!stack.empty()){
            int polled = stack.back();
            stack.pop_back();
            count++;
            for (auto i: adjList[polled]){
                inDegree[i]-=1;
                if(inDegree[i] == 0)stack.push_back(i);
            }
        }
        cout << count << endl;
        return numCourses == count;
    }
};