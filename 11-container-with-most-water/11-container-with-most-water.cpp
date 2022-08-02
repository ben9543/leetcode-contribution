class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // Brute force solution:
        //      Check the maximum are for every height 
        //      Width will shrink as the loop goes through
        //      Use two pointers
        //      Take minimum height between two pointers
        
        int low = 0;
        int high = height.size()-1;
        int maxArea = 0;
        while(low < high)
        {
            int area = min(height[low], height[high]) * (high-low);
            maxArea = max(maxArea, area);
            if(height[low]<=height[high])low++;
            else high--;
        }
        return maxArea;
    }
};