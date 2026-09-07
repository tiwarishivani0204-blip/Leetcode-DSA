class Solution {
    public int distinctSubseqII(String s) {
        long MOD = 1000000007;
        long dp = 0;
        long[] last = new long[26];
        for (char c : s.toCharArray()) {
            int x = c - 'a';
            long newDp = (2 * dp + 1 - last[x] + MOD) % MOD;
            last[x] = dp + 1;
            dp = newDp;
        }
        return (int) dp;
    }
}