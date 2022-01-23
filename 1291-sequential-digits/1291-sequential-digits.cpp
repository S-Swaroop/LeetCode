class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> sequentials ;
        for(int i = 1 ; i <= 8 ; i++){
            generate(sequentials , low , high , i + 1 , i) ;   
        }
        sort(sequentials.begin() , sequentials.end()) ;
        return sequentials ; 
    }
private: 
    void generate(vector<int> &a , int low , int high , int curr_start , int curr_num){
        if(curr_start == 10){
            return ;
        }else{
            curr_num = curr_num * 10 + curr_start ;
            if(curr_num > high) return ;
            if(curr_num >= low && curr_num <= high){
                a.push_back(curr_num) ;
            }
            generate(a , low , high , curr_start + 1 , curr_num) ;
        }
    }
};