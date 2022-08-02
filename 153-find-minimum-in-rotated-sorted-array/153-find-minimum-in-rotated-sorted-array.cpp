class Solution {
public:
    int findMin(vector<int>& nums) {
        
        /// matching
        //      if mid is smaller than left => left portion is rotated
        //      if mid is greater than right => right portion is rotated
        //      Need to take the rotated portion
        //      if left < mid && mid < right => we are on the sorted portion
        //      => return left
        //      There is always going to be an answer
        
        // Edge cases:
        //      [1]
        //      [4,5,6,7,8,9,0,1,2]
        //          [9,0,1,2] => 
        
        // How can we be sure if mid is not the smallest?
        // => if mid is greater than r
        
        int l = 0, r = nums.size()-1;
        while(l < r)
        {
            int mid = floor((l+r)/2);
            if(nums[l] <= nums[mid] && nums[mid] <= nums[r])return nums[l];
            
            if(nums[r] < nums[mid])
                l = mid + 1;
            else
                r = mid;
        }
        
        return nums[l];
    }
};