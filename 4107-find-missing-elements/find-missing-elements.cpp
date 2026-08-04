class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min = *min_element(nums.begin(),nums.end());
        int max = *max_element(nums.begin(),nums.end());
        unordered_set<int>s(nums.begin(),nums.end());
        vector<int>ans;
        for(int x = min + 1; x < max; x++){
            if(!s.count(x)){
                ans.push_back(x);
            }
        }
        return ans;
    }
};