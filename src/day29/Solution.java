class Solution {

    public int minOperations(int[] nums, int k) {
        int x = 0, count = 0;
        for (int i : nums) {
            x ^= i;
        }

        while (k != x) {
            if (k % 2 != x % 2) {
                ++count;
            }
            k /= 2;
            x /= 2;
        }
        return count;
    }
}