#include <cmath>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size()==1){
            if (nums[0] == target)return 0;
            else return -1;
        }
        int mid;
        int low = 0;
        int high = nums.size()-1;
        while (low <= high){
            mid = low + floor((high - low)/2);
            cout << mid << endl;
            if (nums[mid] == target)return mid;
            else if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        
        if (nums[mid] == target) return mid;
        else return -1;
    }
};