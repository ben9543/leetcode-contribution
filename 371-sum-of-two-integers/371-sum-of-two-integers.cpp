class Solution {
public:
    int getSum(int a, int b) {

        while(b != 0)
        {
            int carry = (a&b);
            a ^= b;
            b = (unsigned)carry << 1;
        }
        return a;
    }
};