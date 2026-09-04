class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;

        int[] sMin = new int[n];
        sMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            sMin[i] = Math.min(nums[i], sMin[i + 1]);
        }

        int pMax = nums[0];

        for (int i = 0; i < n; i++) {
            pMax = Math.max(pMax, nums[i]);
            if (pMax - sMin[i] <= k) {
                return i;
            }
        }
        return -1;
    }
}