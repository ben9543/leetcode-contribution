class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       k = nums.size() - k; 
       return quckSelect(nums, k, 0, nums.size()-1);
    }
    
    int quckSelect(vector<int>& nums, int k, int l, int r){
        
        // Select piovt as the farthest element in the current partition
        int pivot = nums[r];
        int bigger = l;
        
        // Swap any elements bigger than pivot
        for (int i = l; i < r; i++){
            
            // bigger does not increase when nums[i] is bigger than pivot.
            // Therefore, bigger will always pointing at the leftmost element
            // that is bigger than the pivot
            if(nums[i] <= pivot){
                swap(nums[i], nums[bigger]);
                bigger++;
            }
        }
        
        // Handle pivot
        swap(nums[r], nums[bigger]);
        
        if(bigger > k)      return quckSelect(nums, k, l, bigger-1);
        else if(bigger < k) return quckSelect(nums, k, bigger+1, r);
        else                return nums[bigger];
    }
};