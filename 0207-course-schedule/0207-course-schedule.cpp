class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> matrix(numCourses, vector<int>());
        unordered_set<int> visited;
        for(auto p : prerequisites){
            int wantToTake = p[0];
            int shouldTake = p[1];
            matrix[wantToTake].push_back(shouldTake);
        }
        for(int course = 0; course < numCourses; course++){
            if(!isPossible(course, matrix, visited))
                return false;
        }
        return true;
    }
    
    // When there is a cycle, you cannot finish it.
    bool isPossible(int course, vector<vector<int>>& matrix, unordered_set<int>& visited){
        vector<int> prerequsites = matrix[course];
        if(visited.find(course) != visited.end())return false;
        visited.insert(course);
        for(auto p : prerequsites){
            if(!isPossible(p,matrix,visited))return false;
        }
        visited.erase(course);
        
        // The course can be finished. So next time we don't have to check
        // This is same as using a set canBeFinished.
        matrix[course] = {};
        return true;
    }
};