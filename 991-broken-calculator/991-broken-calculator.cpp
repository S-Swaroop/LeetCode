class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if (target == startValue) {
            return 0 ; 
        } else if (target < startValue) {
            return startValue - target ; 
        } else {
            if (target % 2 == 0) {
                return 1 + brokenCalc(startValue , target / 2) ;
            } else {
                return 1 + brokenCalc(startValue , target + 1) ;
            }
        }
    }
};