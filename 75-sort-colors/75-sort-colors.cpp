class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0, counter = 0;
        
        for(auto n : nums){
            if(n==0)red++;
            else if(n==1)white++;
            else blue++;
        }
        
        while(red){
            nums[counter] = 0;
            red--;
            counter++;
        }
        while(white){
            nums[counter] = 1;
            white--;
            counter++;
        }
        while(blue){
            nums[counter] = 2;
            blue--;
            counter++;
        }
    }
};