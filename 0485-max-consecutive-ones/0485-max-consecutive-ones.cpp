class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int maxi=0;
        for(int i=0; i<nums.size(); i++){
            ans++;
            if(nums[i]==0){
                ans=0;
            }
            maxi=max(ans,maxi);



        }

        return maxi;
    }
};