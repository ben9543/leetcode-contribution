class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int aptr = 0;
        int bptr = m-1;
        
        int row = 0;
        
        while(aptr <= bptr){
            int mid = floor((aptr+bptr)/2);
            // check if the target value is in
            // matrix[mid][0] <= target <= matrix[mid][n-1]
            if(matrix[mid][0] > target){ // move bptr
                bptr = mid-1;
            } else if(matrix[mid][n-1] < target){ // move aptr
                aptr = mid+1;
            } else {
                row = mid;
                break;
            }
        }
        aptr = 0;
        bptr = n-1;
        while(aptr <= bptr){
            int mid = floor((aptr+bptr)/2);
            if(matrix[row][mid] > target){ // move bptr
                bptr = mid-1;
            } else if(matrix[row][mid]< target){ // move aptr
                aptr = mid+1;
            } else {
                return true;
            }
        }
        return false;
    }
};