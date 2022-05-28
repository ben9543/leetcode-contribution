/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        unsigned long long int low = 1;
        unsigned long long int high = n;
        unsigned long long int mid = 0;
        if (guess(n) == 0) return n;
        while (low <= high){
            double temp = (low+high)/2;
            mid = floor(temp);
            cout << mid << ":" << guess(mid) << endl;
            if (guess(mid) == 1){ // guess is bigger than pick
                low = mid+1;
            } else if(guess(mid) == -1){ // guess is less than pick
                high = mid-1;
            } else {
                return mid;
            }
            cout << "High: " << high << "\tLow: " << low << endl;
        }
        return mid;
    }
};