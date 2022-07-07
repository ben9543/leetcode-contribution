class Solution {
public:
    int countPrimes(int n) {
        // 1. Understanding
        // Input: integer => range of the numbers
        // Output: integer => number of the primes
        // 2. Matching
        // isPrime => recursive & heavy ...
        // 3. Planning
        // hashmap => that stores the information of if the integer is a prime or not.
        //         => so that we don't have to calculate whether the integer is a prime or not all the way from the bottom
        //         the way how to find if n is a prime: i%m => prime  see if the modulo function gives you a 0
        //   1) Need to store primes to the hashmap
        //   2) If the hashmap says the number is not visited, the number is prime. 
        //   3) In the every loop I am going to iterate all multiples of the prime that we found.
        //      2 => 2*2 , 2*3 .. < n => false
        // 4. Implementation
        
        // Base case
        if(n == 0 || n == 1 || n == 2)return 0;
        
        vector<bool> isPrimes(n+2, true);
        int count = 0;
        for (int i = 2; i < n; i++){
            
            // Check if the number is a prime
            if(isPrimes[i]){
                
                count++;
                // Checking all the multiples of the prime
                for (int j = 2; i*j < n; j++){
                    isPrimes[i*j] = false;
                }
            }
        }
        return count;
    }
};