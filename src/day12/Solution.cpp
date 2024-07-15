class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), ans=0, lMax = INT_MIN, rMax = INT_MIN;
        for (int l=0, r=n-1; l<r; ) {
            lMax = max(lMax, height[l]);
            rMax = max(rMax, height[r]);
            if (lMax < rMax) {
                ans += lMax - height[l++];
            } else {
                ans += rMax - height[r--];
            }
        }

        return ans;
    }
};