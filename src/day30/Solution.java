class Solution {
    public long wonderfulSubstrings(String word) {
        long[] count = new long[1024];
        count[0] = 1;
        int mask = 0;
        long ans = 0;
        for (char c :  word.toCharArray()) {
            int idx = c - 97;
            ans += count[mask ^= 1 << idx];
            for (int i=1; i<=512; i*=2) {
                ans += count[mask ^ i];
            }
            ++count[mask];
        }
        return ans;
    }
}