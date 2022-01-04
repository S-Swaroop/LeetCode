class Solution {
public:
    int bitwiseComplement(int n) {
        return (n <= 1 ? (n + 1) % 2 : (~n & ((1 << ((int)log2(n) + 1)) - 1))) ; 
    }
};