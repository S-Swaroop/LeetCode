class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int , int> freq ;
        for (int &i : arr)  freq[i]++ ;
        priority_queue<int> pq ; 
        for (auto &i : freq)    pq.push(i.second) ;
        int n = arr.size() , set_size = 0 ;
        while (n > (int)arr.size() / 2) {
            n -= pq.top() ; 
            pq.pop() ;
            set_size++ ;
        }
        return set_size ;
    }
};