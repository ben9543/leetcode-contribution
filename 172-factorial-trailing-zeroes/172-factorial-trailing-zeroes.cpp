class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while(n >= 5){
            count += floor(n/5);
            n = floor(n/5);
        }
        return count;
    }
};