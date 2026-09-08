class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) return 0;
        if (n < 1000000) return n - 999;
        return 900001 + (n - 999999);
    }
};