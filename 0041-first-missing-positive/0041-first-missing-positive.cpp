class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> mp;

        for(int i: nums){
            mp[i]++;
    
        }

        int ans=1;


        for(auto it: mp){
            if(it.first==ans){
               ans++;
            }
            


        }
        return ans;
    }
};