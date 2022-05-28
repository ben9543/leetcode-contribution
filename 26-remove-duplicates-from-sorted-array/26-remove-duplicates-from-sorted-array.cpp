class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int aPtr = 0;
        int bPtr = 1;
        int count = 1;
        if (nums.size() == 1){
            return count;
        }
        while(bPtr < nums.size()){
            if (nums[aPtr] == nums[bPtr]){
                ++bPtr;
            }else{
                nums[++aPtr] = nums[bPtr];
                ++count;
            }
        }
        return count;
    }
};