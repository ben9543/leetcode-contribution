class Solution {
public:
    int countPrimes(int n) {
        
        // Base case
        if (n == 1 or n == 0 or n == 2) return 0;
        
        // Implementation
        int count = 0;
        vector<bool> isPrime(n+2, true);
        for (int i = 2; i < n; i++){
            if(isPrime[i]){
                count++;
                
                // Mark all multiples of i as false
                for(int j = 2; i*j < n; j++){
                    isPrime[i*j] = false;
                }
            }
        }
        
        return count;
    }
};