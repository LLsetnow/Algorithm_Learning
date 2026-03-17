class Solution {
    public:
    long long countCommas(long long n) {
        long long cnt = 0;
        for(long long i = 1000; i <= n; i++){
            long long digits = to_string(i).length();
            cnt += (digits - 1) / 3;
        }
        return cnt;
    }
};