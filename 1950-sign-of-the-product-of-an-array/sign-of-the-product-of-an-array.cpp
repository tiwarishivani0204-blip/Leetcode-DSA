class Solution {
public:
    int signFunc(vector<int>& nums){
        int product = 1;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == 0)
                return 0;
            if(nums[i] < 0)
                product = -product;
        }
            return product;
        }
    int arraySign(vector<int>& nums) {
        return signFunc(nums);
    }
};