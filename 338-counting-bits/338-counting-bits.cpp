class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        int baseNum = 0;
        int baseCount = 0;
        for (int i = 0; i <= n; i++){
            int count = 0;
            if(i == pow(2, baseCount+1)){
                ++baseCount;
                baseNum = pow(2, baseCount);
            }
            cout << i << ":" << baseNum << endl;
            // Update count
            //	count = res[baseNum] + res[i - baseNum]
            if(i == 0)res[i] = i;
            else if(i == 1)res[i] = i;
            else if(baseNum == i)res[i] = 1;
            else res[i] = res[baseNum] + res[i - baseNum];
        }
        return res;

    }
};