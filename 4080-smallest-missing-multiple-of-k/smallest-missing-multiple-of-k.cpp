class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> ans(101);
        int count = 100;
        for (int i = 0; i <= count; i++) {
            ans[i] = k * (i + 1);
        }
        for (int i = 0; i <= count; i++) {
            bool found = false;
            for (int j = 0; j < nums.size(); j++) {
                if (ans[i] == nums[j]) {
                    found = true;
                    break;
                }
            }
            if (!found)
                return ans[i];
        }
        return -1;
    }
    };