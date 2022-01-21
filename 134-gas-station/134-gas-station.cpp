class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size() ; 
        int partial_sum = 0 , min_sum = INT_MAX , index = -1 ; 
        for(int i = 0 ; i < n ; i++){
            partial_sum += (gas[i] - cost[i]) ;
            if(min_sum > partial_sum){
                min_sum = partial_sum ; 
                index = i + 1 ; 
            }
        }
        return partial_sum >= 0 ? index % n : -1 ; 
    }
};