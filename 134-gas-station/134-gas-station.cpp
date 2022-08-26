class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        // Check the basecase
        int sumOfGas = 0;
        int sumOfCost = 0;
        
        for(int i = 0; i < gas.size(); i++){
            sumOfGas+=gas[i];
            sumOfCost+=cost[i];
        }
        
        if(sumOfGas < sumOfCost)return -1;

        int total = 0; 
        int res = 0;
        int start = 0;
        
        for (int i = 0; i < gas.size(); i++){
            total += (gas[i] - cost[i]);
            if(total < 0){
                
                // Reset total and start
                total = 0;
                start = i+1;
            }
        }
        return start;
    }
};