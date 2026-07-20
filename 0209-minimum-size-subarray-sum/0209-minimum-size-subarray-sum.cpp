class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0;
        int high=0;
        int sum=0;
        int mini=INT_MAX;;

        while(high<nums.size()){
            sum=sum+nums[high];
            while(sum>=target){
                mini=min(mini,high-low+1);
                sum=sum-nums[low];
                low++;
            }
            high++;
            
        

        }
        if(mini==INT_MAX){
            return 0;

        } 
        else{
            return mini;
        }
        
    }
};