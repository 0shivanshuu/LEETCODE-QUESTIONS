class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=0;
        int i=nums.size()-2;
        int j=nums.size()-1;

        sort(nums.begin(),nums.end());

        // for(int i=0; i<nums.size(); i++){
        //     maxi=max(maxi,((nums[i]-1)*(nums[j]-1)));
        //     if(j<nums.size()-1){

        //         j++;
        //     }
        // }
        
        // return maxi;
        return (nums[i]-1)*(nums[j]-1);

    }
};