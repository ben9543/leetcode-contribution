class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // If target is less than mid
        //      => if target is greater than l => take left
        //         else take right
        // If target is greater than mid
        //      => if target is less than r => take right
        //      => else take left
        
        int l = 0, r = nums.size()-1;
        while(l <= r)
        {
            int mid = floor((l+r)/2);
            cout << nums[mid] << endl;
            
            if(nums[mid] == target)return mid;
            
            // Which portion are we in?
            // Mid is on the left sorted portion 
            if(nums[l] <= nums[mid]){
                
                // Discard left side if target is greater than the mid
                if(target > nums[mid]){
                    l = mid+1;
                
                // Discard left side if target is less than the left pointer (smallest value of left side)
                } else if(target < nums[l]){
                    l = mid+1;
                    
                // Otherwise, target is in the range of l .. mid. Take the left side
                } else {
                    r = mid-1;
                }
            }
            
            // Mid is on the right sorted portion 
            else{
                
                // Discard the right side. Target is on the left side.
                if(target < nums[mid]){
                    r = mid - 1;
                    
                // Discard the right side. 
                // If the portion is sorted and the target is greater than nums[r] (biggest) target is on the left side.
                } else if(target > nums[r]){
                    r = mid - 1;
                
                // Otherwise, take the right side
                } else {
                    l = mid + 1;
                }
            }
            
        }
        return -1;
    }
};