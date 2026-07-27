class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int i=nums.size()-1;
        int j=nums.size()-2;
        int k=nums.size()-3;

        sort(nums.begin(), nums.end());

        int maxi=0;

        maxi=max(nums[0]*nums[1]*nums[i], nums[j]*nums[k]*nums[i]);
        return maxi;

    }
};