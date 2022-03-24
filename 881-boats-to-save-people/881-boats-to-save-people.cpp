class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.rbegin() , people.rend()) ;
        int boats = 0 ;
        int n = people.size() , i = 0 , j = n - 1 ; 
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                i++ ; 
                j-- ; 
                boats++ ;
            } else {
                i++ ; 
                boats++ ;
            }
        }
        return boats ;
    }
};