class Solution {
    public int findRotateSteps(String ring, String key) {
        int[][] dp = new int[ring.length()][key.length()];

        for(int[] row: dp) Arrays.fill(row, -1);

        return solve(ring, 0, key, 0, dp);

    }

    private int solve(String ring, int curr, String key, int keyIndex, int[][] dp){
        if(keyIndex == key.length()) return 0;

        if(dp[curr][keyIndex] != -1) return dp[curr][keyIndex];

        int ans = Integer.MAX_VALUE;
        for(int i=0; i<ring.length(); i++){
            if(ring.charAt(i) == key.charAt(keyIndex)){
                int minSteps = Math.min(Math.abs(i - curr), ring.length() - Math.abs(i - curr));
                minSteps += solve(ring, i, key, keyIndex+1, dp)+1;
                ans = Math.min(minSteps, ans);
            }
        }

        return dp[curr][keyIndex] = ans;
    }

}